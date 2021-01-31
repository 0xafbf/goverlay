# game overlay

fork of https://github.com/hiitiger/gelectron

![demo](https://raw.githubusercontent.com/honzapatCZ/gelectron/master/screenshot/gelectron3.gif)

Use the power of web to inject any web app to overlay in your game

## Features

use the power of web to inject any web app to overlay in your game

- electron offscreen window overlay in game
- dx11 api support
- dx10 api support
- dx9 api support
- multi windows support
- window z-index and focus
- in game sync drag and resize
- window draw policy
- input intercepting by manually control
- custom shaped window (alpha test for mouse handling)
- input intercepting by auto mouse check

## Requirements

- Visual Studio 2019 (C++ desktop workspace, winsdk 10.0.18362).
- Python 2 (`add to PATH`)

## Build

### node native-addons

For `electron-overlay` and `node-ovhook`

```bash
    cd client
    npm link ../electron-overlay
    npm link ../node-ovhook
    npm i
    npm run compile:electron
    npm run build
    npm run start
```

### Recompile game-overlay dll

In default they are precompiled under `client/dist/overlay` but if you are making changes you might want to compile on your own

1. copy files [`n_overlay.dll`, `n_overlay.x64.dll`, `n_ovhelper.exe`, `n_ovhelper.x64.exe`] from directory `game-overlay\bin\Release` to directory `node-ovhook\build\Release`

## Test

1. build node projects
2. run demo client
3. click start button to start overlay
4. start the game you want to inject to and wait for it game window to show
5. input the window title(or part of the title) of the game, and click the inject button

## Usage

Check doc/doc.md for usage in your own projects
