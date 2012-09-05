#ifndef __SCENES_H__
#define __SCENES_H__


class TestScene : public Scene {
private:
	OGLFT::Filled* monofont;
	FT_Library library;
public:
	TestScene();
	void render(bool focus);
};


#endif
