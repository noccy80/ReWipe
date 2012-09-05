#ifndef __FS_H
#define __FS_H

#include <physfs.h>
#include <string>
#include <vector>
#include <SDL/SDL.h>
#include <cmath>
#include <GL/glew.h>

class Fs {
private:
	static Fs* instance;
public:
	Fs(const char* base);
	static Fs* getInstance();
	int mount(const char* path, const char* mountpoint);
	SDL_Surface* readSurface(const char* file);
	char* readBinary(const char* file, unsigned long* size);
};

#endif
