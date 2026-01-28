# miniRT (WIP)

Minimal ray tracer built with **MiniLibX**.  
Generates 3D scenes using basic ray tracing techniques.

## Overview

This project renders computer-generated images representing a 3D scene viewed
from a camera, composed of simple geometric objects and illuminated by a basic
lighting system.

The program parses a `.rt` scene description file and displays the rendered image
in a window.

## Features (Current / Planned)

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
- Real-time window rendering using MiniLibX

## Constraints

- **Authorized external functions**
  - `open`, `close`, `read`, `write`
  - `printf`, `malloc`, `free`
  - `perror`, `strerror`, `exit`
  - `gettimeofday`
  - All functions from `math.h` (compile with `-lm`)
  - All MiniLibX functions
- **Libft**: authorized
- Must use **MiniLibX** (system version or compiled from sources)
- Window management must remain fluid (minimize, focus change, etc.)

## Scene Description (`.rt`)

- First argument must be a `.rt` file
- Elements can appear in any order
- One or more spaces separate element fields
- One or more line breaks separate elements
- Elements defined with a **capital letter** may only be declared once
- Objects support:
  - Size configuration (sphere diameter, cylinder width/height)
  - Proper intersection handling, including object interiors

## Controls

- `ESC` — close window and exit cleanly
- Window close button (red cross) — exit cleanly

## Build
```bash
make
```
Make sure MiniLibX (MLX42) is correcty installed and linked.

## Run
- `./miniRT scenes/example.rt`

## Status
- **Work in progress**
- Rendering accuracy, performance optimizations, and edge cases are still being improved.

## Resources
- MiniLibX documentation
- Ray Tracing in One Weekend (concept reference)
- The Ray Tracer Challenge
- `man math.h`