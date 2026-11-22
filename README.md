# Sand-Box

A falling-sand physics simulation.

Place elements such as sand, water, fire or acid anywhere in the window and watch them interact. The project is written in C++ with SFML and targets anyone who wants a small sandbox to play with or a compact example of a cellular simulation.

## Table of contents

- [Sand-Box](#sand-box)
	- [Table of contents](#table-of-contents)
	- [How it works](#how-it-works)
	- [Tech stack](#tech-stack)
	- [Repository structure](#repository-structure)
	- [Prerequisites](#prerequisites)
	- [Installation](#installation)
	- [Configuration](#configuration)
	- [Running locally](#running-locally)
	- [Useful scripts](#useful-scripts)
	- [License](#license)

## How it works

1. **Grid**: the window is split into square cells of 5 pixels. The 1600x900 window gives a 320x180 grid. Each cell holds one element.
2. **Elements**: every element is a class in `src/elements`. Each one belongs to a state (solid, dust, liquid or gas) that defines how it moves, and adds its own interactions on top.
3. **Simulation**: on every frame, the grid updates each cell. The window is capped at 120 frames per second.
4. **Interactions**: elements react to their neighbors. Fire ignites wood and melts snow and ice, burning wood leaves ash, steam can condense back into water, snow and ice melt over time, and acid dissolves other elements.
5. **Input**: hold the left mouse button to place the selected element. Right-click shows or hides the selection bar, and a left click on the bar selects an element.

| Element | State | Behavior |
| --- | --- | --- |
| Air | Solid | Empty cell, used to erase |
| Sand | Dust | Falls and forms hills |
| Water | Liquid | Falls and spreads sideways |
| Steam | Gas | Rises, can condense into water |
| Wood | Solid | Fixed, burns |
| Fire | Own class | Ignites wood, melts snow and ice into water, turns water into steam |
| Ash | Dust | Left by burning wood, falls like sand |
| Stone | Solid | Fixed, does not burn |
| Acid | Liquid | Dissolves other elements, dissolves in water |
| Snow | Dust | Falls, melts into water over time |
| Ice | Solid | Fixed, melts into water over time |

## Tech stack

| Layer | Technologies |
| --- | --- |
| Language | C++ |
| Graphics and input | SFML |
| Build | Xmake |

## Repository structure

```
.
├── assets/             Element icons and window icon
├── src/
│   ├── display/        Grid, selection bar and image rendering
│   ├── elements/       One class per element
│   │   └── states/     Base behaviors: solid, dust, liquid, gas
│   ├── utils/          Vector2 and helpers
│   ├── config.cpp      Window and grid settings
│   └── main.cpp        Entry point and main loop
└── xmake.lua           Build configuration
```

Every file in `src/` is a `.cpp` and `.h` pair. To add an element, create a class in `src/elements` that extends the base class of its state.

## Prerequisites

- [Git](https://git-scm.com/downloads)
- [Xmake](https://xmake.io/#/getting_started?id=installation), which downloads SFML on the first build
- A C++ compiler supported by Xmake

## Installation

```bash
git clone git@github.com:maxencebonamy/Sand-Box.git
cd Sand-Box
```

```bash
xmake
```

Prebuilt Windows executables are available on the [releases page](https://github.com/maxencebonamy/Sand-Box/releases).

## Configuration

There is no environment file. Settings are constants in [`src/config.cpp`](src/config.cpp), and the project must be rebuilt after a change.

| Constant | Description | Value |
| --- | --- | --- |
| `WINDOW_TITLE` | Window title | `SandBox` |
| `WINDOW_FPS` | Frame rate limit | `120` |
| `WINDOW_SIZE` | Window size, in pixels | `1600 x 900` |
| `WINDOW_FULLSCREEN` | Fullscreen mode | `false` |
| `CELL_SIZE` | Side of a cell, in pixels | `5` |

## Running locally

```bash
xmake run
```

The working directory is the repository root, because the executable loads images from `assets/`.

## Useful scripts

| Command | Effect |
| --- | --- |
| `xmake` | Build the project |
| `xmake run` | Run the executable |
| `xmake f -m release` | Switch to a release build |
| `xmake f -m debug` | Switch to a debug build |

## License

This project is licensed under the [MIT License](LICENSE).
