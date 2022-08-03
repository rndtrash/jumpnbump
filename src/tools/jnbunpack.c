/*
 * unpack.c
 * Copyright (C) 1998 Brainchild Design - http://brainchilddesign.com/
 *
 * Copyright (C) 2001 "timecop" <timecop@japan.co.jp>
 *
 * Copyright (C) 2002 Florian Schulze <crow@icculus.org>
 *
 * This file is part of Jump 'n Bump.
 *
 * Jump 'n Bump is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Jump 'n Bump is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#ifndef _WIN32
#include <unistd.h>
#else
#include <io.h>
#endif

#define FILENAME_LENGTH 12

typedef struct {
	char filename[FILENAME_LENGTH];
	unsigned int offset;
	unsigned int size;
} DirEntry;

#ifndef O_BINARY
#define O_BINARY 0
#endif

int main(int argc, char **argv)
{
	int fd;
	DirEntry *datafile;
	int num_entries, i;

	if (argc < 2) {
		printf("dumbass, specify filename to unpack\n");
		exit(1);
	}

	fd = open(argv[1], O_RDONLY | O_BINARY);
	if (fd == -1) {
		perror("open datafile");
		exit(1);
	}
	/* get number of entries */
	if (read(fd, &num_entries, 4) != 4) {
		perror("read num of entries");
		exit(1);
	}

	printf("%d entries in datafile\n", num_entries);

	datafile = calloc(num_entries, sizeof(DirEntry));
	if (!datafile) {
		perror("malloc failed");
		exit(1);
	}

	if (read(fd, datafile, num_entries * sizeof(DirEntry)) != (ssize_t) (num_entries * sizeof(DirEntry))) {
		perror("read entries");
		free(datafile);
		exit(1);
	}

	printf("Directory Listing:\n");
	for (i = 0; i < num_entries; i++) {
		char filename[FILENAME_LENGTH + 1];
		memset(filename, 0, sizeof(filename));
		strncpy(filename, datafile[i].filename, FILENAME_LENGTH);
		printf("%02d:\t%s (%u bytes)\n", i, filename,
			   datafile[i].size);
	}

	for (i = 0; i < num_entries; i++) {
		int outfd;
		char filename[2 + FILENAME_LENGTH + 1] = "./"; // dotslash + filename + null terminator
		char *buf;

		int j = 2;
		for (int k = 0; datafile[i].filename[k] != '\0' && k < FILENAME_LENGTH && j < 2 + FILENAME_LENGTH; k++) {
			if (datafile[i].filename[k] == '.' && datafile[i].filename[k + 1] == '.') {
				k++; // and one more ++ from for
			} else if (datafile[i].filename[k] != '/' && datafile[i].filename[k] != '\\') {
				filename[j] = datafile[i].filename[k];
				j++;
			}
		}
		filename[j] = '\0';

		printf("Extracting %s ", filename);
		fflush(stdout);

		if (remove(filename) == -1 && errno != ENOENT) {
			perror("cannot remove file");
			exit(1);
		}
		outfd = open(filename, O_RDWR | O_CREAT | O_EXCL | O_BINARY, 0644);
		if (!outfd) {
			perror("cant open file");
			exit(1);
		}
		lseek(fd, datafile[i].offset, SEEK_SET);
		buf = calloc(1, datafile[i].size + 16);
		if (!buf) {
			perror("malloc failed");
			exit(1);
		}

		if (read(fd, buf, datafile[i].size) != datafile[i].size) {
			perror("reading file");
			free(buf);
			exit(1);
		}

		if (write(outfd, buf, datafile[i].size) != datafile[i].size) {
			perror("writing to file");
			free(buf);
			exit(1);
		}

		close(outfd);
		free(buf);
		printf("OK\n");
	}
	close(fd);
	return 0;
}
