
*Project: ReWipe*

-----



# Building

## Dependencies

  - *OGLFT* - For font generation
  - *PhysFs* - For archive file system ops
  - *SDL* - Event loop and input
  - *GLU* - OpenGL
  - *gle* - OpenGL Extruction library
  - *freetype* - For loading truetype fonts



# Helping Out

## ToDo/Needed:

  - Programmers with OpenGL skills
  - Art designers / 3D Modellers / Level designers
  - Musicians
  - Packagers / Someone to implement autotools configure/make
  - 
  
## Current crew:

*Programmers:*
  - Noccy
  - TehMini
  - Your name here

*Graphics/Assets:*
  - Noccy
  - Your name here

*Music/Sound:*
  - Noccy
  - Your name here

## Resources:

  - [Using SDL with OpenGL](http://content.gpwiki.org/index.php/SDL:Tutorials:Using_SDL_with_OpenGL)
     [2](http://osdl.sourceforge.net/main/documentation/rendering/SDL-openGL.html)

  - [TinyXML](http://www.grinninglizard.com/tinyxmldocs/tutorial0.html)

  - [OpenGL Accumulation Buffers (Motion Blur)](http://r3dux.org/2010/10/how-to-draw-motion-blur-trails-using-the-accumulation-buffer-in-opengl/)



# Engine

The Fusion Engine is a fully Open Sourced 3D Game engine built for the
ReWipe racing game. It is desiged to recreate the feeling of the WipeOut
game series, offering futuristic anti-gravity racing at high speeds.

## (Planned) Features

  - Motion blur to increase the feeling of speed
  - Basic physics simulation
  - Networking support

### Basic Physics Simulation

The vehicle will be hovering above the ground. As such it needs to react
accordingly when a force is excerted on it, as well as showing a slight
wobble.

Acceleration should affect the vehicle, pushing the front down and 
breaking should do the reverse, lifting it up. Jumps should offer a
nice smooth trajectory.

The wobble can be reproduced by transforming the position of the crafts
by something along the lines of:

    F = factor for wobble scaling
    E = expression max, ex 5.0f
    T = timer ticks
    Wx = E·sin(TF);
    Wy = E·cos(TF/2);

### Weapons and Projectiles

This includes:

  * Mines
  * "Dumb" Rockets
  * Missiles
  * Bombs
