
#include <stdlib.h>
#include "SceneObj.h"
#include "raylib.h"
#include <iostream>
#include <string>

class Game {
public:
	Game();

	void Run();

private:

	void Update(float deltaTime);
	void Draw();

	void Load();
	void Unload();

	void Shoot(Vector2 mousePos);
private:

	int m_windowWidth = 640;
	int m_windowHeight = 480;
};