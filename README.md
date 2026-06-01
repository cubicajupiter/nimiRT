# C-based 3D Ray Tracing Engine

Minimal ray tracer built following The Ray Tracer Challenge book by Jamis Buck and using the **MLX42** library.  
Generates 3D scenes using basic ray tracing techniques.

![Screenshot showing a miniRT render of a sphere cult.](https://github.com/cubicajupiter/nimiRT/blob/main/gallery/miniRT_sphere_cult.png)
![Screenshot showing a miniRT render of Saturn and its rings with the sun in the background.](https://github.com/cubicajupiter/nimiRT/blob/main/gallery/miniRT_saturn_rings.png)
![Screenshot showing a miniRT render of a Japanese torii.](https://github.com/cubicajupiter/nimiRT/blob/main/gallery/miniRT_torii.png)

## Overview

A 42-project implementing a minimal ray tracer.

## Features (Current / Planned)

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

## Controls

- `ESC` — close window and exit cleanly
- Window close button (red cross) — exit cleanly

## Build
```bash
make
```
Makefile downloads and links MLX42 dependencies.

## Run
- `./miniRT scenes/example.rt`

## Status
- Finished for now.

## Resource
- MiniLibX documentation
- Ray Tracing in One Weekend (concept reference)
- The Ray Tracer Challenge
- `man math.h`
