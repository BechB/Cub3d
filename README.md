# Cub3d
Cub3D — 42 School ProjectCub3D is a graphics project inspired by Wolfenstein 3D, the first FPS game ever made. You build a 3D maze renderer from scratch using raycasting — all in C.

Compiling Cub3D — 42
Prerequisites
MiniLibX must be installed. Depending on your OS:
Linux
sudo apt-get install libxext-dev libxrandr-dev libx11-dev libbsd-dev libgl1-mesa-dev
macOS — MiniLibX uses native frameworks, nothing to install.

Compilation
Most 42 repos include a Makefile, so just run:
make
Standard expected rules:
make        # compile
make clean  # remove .o files
make fclean # remove .o files + binary
make re     # fclean + make

Run the program
./cub3D maps/map.cub

What you build
A first-person 3D view of a maze defined by a .cub map file, rendered in real time using the MiniLibX graphics library (42's own wrapper around X11/AppKit).

How it works — Raycasting
No OpenGL, no 3D engine. You cast one ray per vertical column of pixels, calculate where it hits a wall, and draw a vertical slice scaled by distance. The closer the wall, the taller the slice. This creates the illusion of 3D.
Key math involved: DDA algorithm (Digital Differential Analysis) for efficient ray-wall intersection.

Map file (.cub)
The map is defined in a config file containing:
ElementMeaningNO ./pathNorth wall textureSO ./pathSouth wall textureWE ./pathWest wall textureEA ./pathEast wall textureF r,g,bFloor colorC r,g,bCeiling colorThe grid1 = wall, 0 = empty, N/S/E/W = player start + direction
The map must be surrounded by walls and fully valid — map parsing and error handling are a big part of the grade.

Controls
KeyActionW A S DMove forward / back / strafe← →Rotate cameraESCExit

Key technical challenges
Raycasting math — understanding vectors, ray direction, and DDA without a tutorial doing it for you.
Texture mapping — projecting a 2D texture onto each wall slice correctly (calculating the exact X offset on the texture).
Map parsing & validation — rejecting invalid maps cleanly with an error message.
MiniLibX — low-level hooks for keyboard input, window management, image buffers (mlx_image, mlx_put_pixel).
Performance — rendering must be smooth; naive approaches cause flickering or lag.

Bonus features (optional)

Minimap displayed on screen
Mouse rotation
Doors that open/close
Animated sprites
Floor/ceiling textures (instead of flat colors)

