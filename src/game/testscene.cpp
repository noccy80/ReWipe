#include "game.h"
#include "../framework/framework.h"

TestScene::TestScene() {
	
	/*
	 * This code needs patching.
	 */
    //Fs* fs = Fs::getInstance();
    //unsigned long size = 0;
    //char* buf = (char*)fs->readBinary("data/mentone-semibol.ttf", &size);
    //if (size == 0) {
    //    fprintf(stderr,"Unable to load font via physfs!\n");
    //    exit(1);
    //}
    // Code works but need a bit of cleaning up. Leaks as new fonts are
    // initialized on every call to setMode()
    //FT_Init_FreeType(&library);
    //FT_Face face;
    //FT_New_Memory_Face(library, (const unsigned char*)buf, size, 0, &face);
    //monofont = new OGLFT::Filled(face,14);
    
    
    monofont = new OGLFT::Filled("data/FreeSans.ttf",9);
    if ((monofont == 0) | (!monofont->isValid())) {
        fprintf(stderr,"Unable to load font!\n");
        exit(1);
    }
    monofont->setForegroundColor(1.,0.,0.);
	this->monofont = monofont;
	
}

void TestScene::render(bool focus) {

	static int i = 0;
	i++;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();		
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 0, 480, 1, -1);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();		

/*
	GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { -1.0, -1.0, -1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
*/

	glRotatef( (double)i*1, 1.0, 0.0, 0.0 );
	glRotatef( (double)i*2, 0.0, 1.0, 0.0 );
	glScalef( 0.5f, 0.5f, 0.5f );

	// This doesn't seem to work?
	glShadeModel (GL_SMOOTH);

	glBegin(GL_POLYGON);
	glColor3f( 1.0, 1.0, 1.0 );    
	glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
	glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
	glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
	glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple

	glEnd();

	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(   0.5,  1.0, 1.0 );
	glVertex3f(  0.5, -0.5, 0.5 );
	glVertex3f(  0.5,  0.5, 0.5 );
	glVertex3f( -0.5,  0.5, 0.5 );
	glVertex3f( -0.5, -0.5, 0.5 );
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(  0.5,  0.5,  1.0 );
	glVertex3f( 0.5, -0.5, -0.5 );
	glVertex3f( 0.5,  0.5, -0.5 );
	glVertex3f( 0.5,  0.5,  0.5 );
	glVertex3f( 0.5, -0.5,  0.5 );
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(   0.5,  1.0,  0.5 );
	glVertex3f( -0.5, -0.5,  0.5 );
	glVertex3f( -0.5,  0.5,  0.5 );
	glVertex3f( -0.5,  0.5, -0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  0.5,  1.0 );
	glVertex3f(  0.5,  0.5,  0.5 );
	glVertex3f(  0.5,  0.5, -0.5 );
	glVertex3f( -0.5,  0.5, -0.5 );
	glVertex3f( -0.5,  0.5,  0.5 );
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0,  0.5 );
	glVertex3f(  0.5, -0.5, -0.5 );
	glVertex3f(  0.5, -0.5,  0.5 );
	glVertex3f( -0.5, -0.5,  0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();

	glFlush();

	// Draw debug information
	
	char buffer[64];

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();
	glOrtho(0, 640, 0, 480, -1, 1);

// TODO: Move this code to the game main loop
	static int tickfirst;
	static int ticklast;
	int tickcurrent = SDL_GetTicks();
	if (!tickfirst) tickfirst = tickcurrent-1;
	float elapsed = (((float)tickcurrent/1000)-((float)tickfirst/1000));
	float vfps = (float)(i / elapsed);
	
	int mslast = (tickcurrent - ticklast);
	int fps = 10;
	// How long to wait
	unsigned long tpf = 1000/fps;
	unsigned long msl = mslast/1000;
	if (msl < tpf) {
		SDL_Delay(tpf-msl);
	}
	ticklast = tickcurrent;
	
	sprintf(buffer, "Frame %d (%.1f FPS) - IFD %ld", i, vfps,tpf-msl );
	this->monofont->draw(10,450, buffer);
	sprintf(buffer, "Focus %s", (focus)?"true":"false");
	this->monofont->draw(10,430, buffer);

	glFlush();
	
}
