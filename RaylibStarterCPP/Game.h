#pragma once
#include "raylib.h"

class Game {
public:
	Game();
	~Game();

	void Run();

private:

	void Update(float deltaTime);
	void Draw();

};