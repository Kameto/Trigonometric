#pragma once
#include "Shape.h"

class Scene
{
public:
	Scene();
	~Scene();
	void Update();
	void Draw();

private:
	Shape* sh;

};