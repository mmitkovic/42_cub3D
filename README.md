# 42_cub3D

This project is inspired by the world-famous Wolfenstein 3D game, which is
considered the first FPS ever created. Its main goal is to introduce developer to beautiful word of **raycasting** - using mathematical vectors and trigonometry to travel through plain map (X,Y coordinate system). By implementing elegantly derivated formulas, math being powered just by the CPU, lets us render 3D image from 2d grid. Pixel by pixel, drawing textures slices in real time. Old style.

## Tech
- Language: 100% in C
- Dependencies: MiniLibX (Linux)

## Compile & run
```bash
To build files, type "make" in root directory.
Next start the executable file with path to particular map as an argument. (examples loaded in assets)
./cub3d [assets/maps/map.cub]
