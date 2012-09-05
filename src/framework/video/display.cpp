#include "../framework.h"

Display* Display::instance = NULL;

/* static */
Display* Display::getInstance() {
	if (!Display::instance) {
		Display::instance = new Display();
	}
	return Display::instance;
}

Display::Display() : dwidth(0), dheight(0) {
	if (!Display::instance) Display::instance = this;
	LOG("Initializing video device...\n");
	SDL_InitSubSystem(SDL_INIT_VIDEO);
}

Display::~Display() {
	LOG("Closing video device...\n");
	if (this->dsurf) {
		SDL_FreeSurface(this->dsurf);
	}
}

int Display::initialize(unsigned long dwidth, unsigned long dheight) {
	this->dwidth = dwidth;
	this->dheight = dheight;
	LOG("Setting resolution %ldx%ld\n", dwidth, dheight);

	// Set relevant GL parameters
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
 
//    glEnable(GL_MULTISAMPLE);
//    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1) ;
//    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4) ;
 
    // Specify accumulation buffer bits per pixel
    // Note: This must be done BEFORE the surface is initialised!
    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,   16);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,  16);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 16);
    
    
	this->dsurf = SDL_SetVideoMode(this->dwidth, this->dheight, 32, SDL_OPENGL);
	if ( this->dsurf == NULL )
	{
		fprintf(stderr, "Unable to set video-mode: %s\n",
		SDL_GetError());
		return 1;
	}

	LOG("OpenGL Version: %s\n", (const char*)glGetString(GL_VERSION));
	LOG("OpenGL Vendor: %s\n", (const char*)glGetString(GL_VENDOR));
	LOG("OpenGL Renderer: %s\n", (const char*)glGetString(GL_RENDERER));

	glClearColor (0.0, 0.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();

	return 0;
}
