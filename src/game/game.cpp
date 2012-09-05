#include "game.h"


Game::Game() {
	this->m_sr = new SceneRenderer();
	this->m_r = new Renderer();

}

void Game::initialize() {

	TestScene* ts = new TestScene();
	this->m_sr->pushScene(ts);
	
}

void Game::mainloop() {

	this->initialize();

    SDL_Event event;
    
    bool done = false;
    while(!done) {
		
		while (SDL_PollEvent(&event)) {
		
			switch(event.type) {
				case SDL_USEREVENT:
					handleUserEvents(&event);
					break;
					
				case SDL_KEYDOWN:
					// Handle any key presses here.
					break;

				case SDL_MOUSEBUTTONDOWN:
					// Handle mouse clicks here.
					break;

				case SDL_QUIT:
					done = true;
					break;
					
				default:
					break;
			}   // End switch

		}

		this->updateWorld();
		this->m_r->renderScene(this->m_sr);
            
    }   // End while
    
}

void Game::updateWorld() { }

void Game::handleUserEvents(SDL_Event* event) {
	
    switch (event->user.code) {
            
        default:
            break;
    }
}
