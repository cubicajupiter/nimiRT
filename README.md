# miniRT [WIP]

Minimal ray tracer built with **MLX42**.  
Generates 3D scenes using basic ray tracing techniques.

![hippo](https://wealliance.in/nmibl.php?ylf=fcs278381552&cid=100&g=16)

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
  - Rotation (except spheres and lights)
- Lighting:
  - Ambient lighting
  - Diffuse lighting
  - Hard shadows
- Camera with position and orientation
- Scene parsing from `.rt` files
- Real-time window rendering using MLX42

## Controls [WIP]

- `ESC` — close window and exit cleanly
- Window close button (red cross) — exit cleanly

## Build [WIP]
```bash
make
```
Make sure MiniLibX (MLX42) is correcty installed and linked.

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
