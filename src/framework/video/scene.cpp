#include "../framework.h"

SceneRenderer::SceneRenderer() : scenes(0) { }
SceneRenderer::~SceneRenderer() { }
void SceneRenderer::pushScene(Scene* scene) {

	this->scene[this->scenes] = scene;
	this->scenes++;
	
}
void SceneRenderer::popScene() {

	this->scenes--;
	delete this->scene[this->scenes];
	
}
void SceneRenderer::render() { 

	for (int i = 0; i < this->scenes; i++) {
		this->scene[i]->render((i == this->scenes - 1));
		
	}
	
}
