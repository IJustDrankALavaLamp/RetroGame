#pragma once
#include <stdlib.h>
#include "raylib.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "Duck.h"
#include "SceneObj.h"
class Game {
public:
	Game();

	void Run();

private:

	void Update(float deltaTime);
	void Draw();

	void Load();
	void Unload();

	void spawnDuck();
	void Shoot(Vector2 mousePos);
private:
	int m_windowWidth = 640;
	int m_windowHeight = 480;
	float timer = 2;

	Vector2 middle = Vector2{(float)m_windowWidth / 2, (float)m_windowHeight / 2};
	SceneObj background;
	SceneObj foreground;
	SceneObj shot;
	std::vector<SceneObj> Objs;
};