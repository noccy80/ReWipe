#
# Generic Makefile for MSP430-based projects
#
# (c) 2011, NoccyLabs.info
#
# Source files and target binary, define your source files here to have them
# compiled, and define the target basename. BUILD defines the default build
# type, as either "lib" or "bin". If bin, an .elf binary will be created as
# well as a .hex file, and if lib an .a library file will be created. To have
# the binary flashed on the device after build, use "bin prog".

# Source files, C, C++  and Assembly
SOURCEC   =
SOURCECPP = \
	main.cpp \
	framework/fs.cpp \
	framework/input/inputcontroller.cpp \
	framework/input/joystick.cpp \
	framework/video/display.cpp framework/video/object.cpp \
	framework/video/scene.cpp framework/video/camera.cpp \
	framework/video/renderer.cpp \
	game/testscene.cpp game/game.cpp
# display.cpp fenix.cpp fs.cpp surface.cpp eventhandler.cpp inputprofile.cpp
# PACK      = content.pk

# bin:binary file, lib:library, prog:program device
BUILD     = bin data

# Target binary without extension.
TARGET    = wiped-bin

# Include paths, f.ex. -I. -Isome/path
INCLUDES  = -I/usr/local/include/oglft -I/usr/include/freetype2 -I. -I./framework

# Libraries to link with, f.ex. -lcomm
# ...and where to find them f.ex. -Llib -Lsome/path
LIBS      = /usr/local/lib/libOGLFT.a -lstdc++ -lphysfs -lSDL -lGL -ltinyxml -lGLU -lgle -lfreetype
LDFLAGS  += $(shell sdl-config --libs) 
CFLAGS   += $(shell sdl-config --cflags)
CXXFLAGS += -DOGLFT_NO_QT
LIBPATH   = -L/usr/local/lib
include ../Makefile.gcc
include ../Makefile.pk
