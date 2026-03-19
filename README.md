# miniRT [WIP]

Minimal ray tracer built following The Ray Tracer Challenge book by Jamis Buck and using the **MLX42** library.  
Generates 3D scenes using basic ray tracing techniques.

![Screenshot showing a miniRT render of asphere cult.]()
![Screenshot showing a miniRT render of Saturn and its rings with the sun in the background.]()
![Screenshot showing a miniRT render of a Japanese torii.]()

## Overview [WIP]

A 42-project implementing a minimal ray tracer.

## Features (Current / Planned) [WIP]

- Ray tracing rendering pipeline
- Supported objects:
  - Sphere
  - Plane
  - Cylinder
- Object transformations:
  - Translation
  - Scaling
  - Shearing
  - Rotation (except spheres and lights)
- Lighting:
  - Ambient lighting
  - Diffuse lighting
  - Specular lighting
  - Hard shadows
- Camera with position and orientation
- Scene parsing from `*.rt` files
- Window creation and image rendering using MLX42

## Controls [WIP]

- `ESC` — close window and exit cleanly
- Window close button (red cross) — exit cleanly

## Build [WIP]
```bash
make
```
Makefile downloads and links MLX42 dependencies.

## Run [WIP]
- `./miniRT scenes/example.rt`

## Status [WIP]
- **Work in progress**
- Rendering accuracy, performance optimizations, and edge cases are still being improved.

## Resources [WIP]
- MiniLibX documentation
- Ray Tracing in One Weekend (concept reference)
- The Ray Tracer Challenge
- `man math.h`
