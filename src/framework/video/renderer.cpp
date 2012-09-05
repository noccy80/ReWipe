#include "../framework.h"

void Renderer::renderScene(SceneRenderer* sr) {

	// Clear the draw and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	if (this->m_motionblur > 0.0f) {
		// Take the contents of the current accumulation buffer and copy it
		// to the colour buffer with each pixel multiplied by a factor
		// i.e. we clear the screen, draw the last frame again (which we 
		// saved in the accumulation buffer), then draw our stuff at its 
		// new location on top of that
		glAccum(GL_RETURN, 0.99f);
 
		// Clear the accumulation buffer (don't worry, we re-grab the 
		// screen into the accumulation buffer after drawing our current 
		// frame!)
		glClear(GL_ACCUM_BUFFER_BIT);	
	}
	
	// Set up the viewport
	glViewport(0, 0, 640, 480);
	
	// Call the rendering chain
	sr->render();
	
	SDL_GL_SwapBuffers();
	if (this->m_motionblur > 0.0f) {
		// Take the contents of the current draw buffer and copy it to 
		// the accumulation buffer with each pixel modified by a factor
		// The closer the factor is to 1.0f, the longer the trails... 
		// Don't exceed 1.0f - you get garbage.
		glAccum(GL_ACCUM, this->m_motionblur);
	}
	
}

void Renderer::setMotionBlur(float strength) {
	
	this->m_motionblur = strength;
	
}
