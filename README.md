# Jump 'n Bump

![Screenshot](/dist/screenshot.png "Screenshot")

This is a game for the whole family. You play cute fluffy little bunnies and
hop on each other's heads.

At the beginning you are in the menu, where you have to let each active player
jump over the tree trunk to enter the play area, and then walk to the right.
You will then enter the arena. The aim is to jump on the other bunnies' heads…

Jump 'n Bump was originally a DOS game by Brainchild Design, which was open
sourced under the GPL license and ported to SDL, and then SDL2.

## Controls

The controls are keyboard layout-independent, which means that regardless of
the layout that you are using (e.g. AZERTY or Dvorak), they are located as if
it were QWERTY.

The controls on a **QWERTY** keyboard are:

- A, W, D to steer Dot
- ←, ↑, → to steer Jiffy
- J, I, L to steer Fizz
- 4, 8, 6 to steer Mijji (on the numeric pad)

You can also use joysticks (main axis and button 1 will be used).

- F10 toggles fullscreen
- ESC ends the game
- F12 closes the game and quits

## Extra levels

Additional levels are available on the website of
[Brainchild Design](http://www.brainchilddesign.com/games/jumpnbump/levels/levels1.html).
You can launch them with `jumpnbump -dat levelname.dat`.

## Networking

Jump 'n Bump can be played in multiplayer over the network. This can be done
with these commands:

Player 1: `jumpnbump -server 1`
Player 2: `jumpnbump -connect <ip_or_hostname_of_player1>`

You have to make sure that the port tcp/11111 is open in your firewall.

You can add -server 2 and -server 3 for 3rd and 4th player, and make sure that all
the players are using the same `-dat level.dat`, if any.

## Compilation

Clone this repo and pull all the submodules with
`git clone --recurse-submodules https://github.com/rndtrash/jumpnbump.git`

To build Jump 'n Bump you will need development libraries for the SDL2, SDL2_mixer, SDL2_net,
BZip2 and Zlib, as well as CMake to generate the Makefiles.

You can then run `cmake -B build` in the root of the repo to configure this project into `build` folder and either
run `cmake --build build` or go to the `build` folder and run `make`.

Jump 'n Bump has the following options available for CMake that can be used with
`cmake -B build -DPARAM=ON -DOTHERPARAM=OFF`:

|Option|Description|Default value|
|------|-----------|-------------|
|DATADIR|The folder where data such as desktop icons and shortcuts is stored.|`${CMAKE_INSTALL_PREFIX}/share`|
|GAMEDATADIR|The folder where game data is stored.|`${CMAKE_INSTALL_PREFIX}/share`|
|USE_SDL|Use SDL2. At the moment there is no point in disabling it.|ON|
|USE_SDL_MIXER|Use SDL2 mixer.|ON|
|USE_NET|Add online multiplayer. Requires SDL2 net.|ON|
|ZLIB_SUPPORT|Use Zlib.|ON|
|BZLIB_SUPPORT|Use BZip2.|ON|

You can install the project with `cmake --install build` or `make install` in the `build` folder. May require root depending on your installation prefix.

## License

Jump 'n Bump is distributed under the GNU General Public License, version 2, or
(at your option) any later version (GPL-2.0+). See the AUTHORS file for
credits.
