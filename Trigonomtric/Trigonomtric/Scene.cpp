#include "Scene.h"

Scene::Scene()
{
	sh = new Shape(SF::mBox, 100);
}

Scene::~Scene()
{
	Release(sh);
}

void Scene::Update()
{
	sh->Update();
}

void Scene::Draw()
{
	sh->Draw();
}