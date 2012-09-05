#include "framework.h"

Fs* Fs::instance = NULL;

Fs::Fs(const char* base) {
	Fs::instance = this;
	PHYSFS_init(base);	
}
Fs* Fs::getInstance() {
	return Fs::instance;
}
int Fs::mount(const char* path, const char* mountpoint) {
	if (PHYSFS_mount(path, mountpoint, 0)) {
		LOG("[fs] Mounted %s on %s...\n", path, mountpoint);
		return true;
	}
	LOG("[fs] Mount attempt failed: %s\n", path);
	return false;
}
SDL_Surface* Fs::readSurface(const char* file) {
	LOG("[fs] Loading surface %s\n", file);
	PHYSFS_file* hfile = PHYSFS_openRead(file);
	if (!hfile) {
		LOG("Error: Not found\n");
		return NULL;
	}
	char *buf = new char[PHYSFS_fileLength(hfile)];
	int length_read = PHYSFS_read (hfile, buf, 1, PHYSFS_fileLength(hfile));    
	PHYSFS_close(hfile);
	if (length_read == 0) {
		LOG("Warning: null-length file\n");
		return NULL;
	}
	SDL_RWops* rw = SDL_RWFromMem(buf, length_read);
	SDL_Surface* tmp = SDL_LoadBMP_RW(rw, 0);
	SDL_RWclose(rw);	
	if (!tmp) {
		LOG("Error: RWop could not create surface from blob\n");
		return NULL;
	}
	return tmp;
}
char* Fs::readBinary(const char* file, unsigned long* size) {
	LOG("[fs] Loading blob %s\n", file);
	PHYSFS_file* hfile = PHYSFS_openRead(file);
	if (!hfile) {
		LOG("Not found\n");
		return NULL;
	}
	char *buf = new char[PHYSFS_fileLength(hfile)];
	unsigned long length_read = PHYSFS_read (hfile, buf, 1, PHYSFS_fileLength(hfile));    
	PHYSFS_close(hfile);
	*size = length_read;

	return buf;
}
