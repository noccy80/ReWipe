#ifndef __VIDEO_H__
#define __VIDEO_H__

class Display {
private:
    static Display* instance;
    unsigned long dwidth;
    unsigned long dheight;
    SDL_Surface* dsurf;
public:
	Display();
	~Display();

	/**
	 * @brief Singleton accessor for Display.
	 * 
	 * @return The singleton instance
	 */
    static Display* getInstance();
    
    /**
     * @brief Initialize video
     * 
     * @return 0 on success
     */
    int initialize(unsigned long dwidth, unsigned long dheight);
    
};

class WorldObject {
protected:	
	/// Vehicles position in the scene
	double px, py, pz;
	/// Vehicles rotation in the scene
	float rx, ry, rz;
public:
	void setPosition(double x, double y, double z);
	void setRotation(float x, float y, float z);
};

class MobileObject : public WorldObject {
protected:
	/// Vehicles velocity in the scene
	float vx,vy,vz;
	/// Vehicles rotational momentum (spin)
	float sx,sy,sz;
public:
	void setVelocity(float x, float y, float z);
	void setSpin(float x, float y, float z);
};

class Camera : public WorldObject {
	
	
};


class Scene {
public:
	virtual void render(bool focused) = 0;
};

#define MAX_SCENES 16
class SceneRenderer {
private:
	int scenes;
	Scene* scene[MAX_SCENES];
public:
	SceneRenderer();
	~SceneRenderer();
	void pushScene(Scene* scene);
	void popScene();
	void render();
};


class Renderer {
private:
	float m_motionblur;
public:
	void renderScene(SceneRenderer* scenerenderer);
	void setMotionBlur(float strength);
};

#endif // __VIDEO_H__
