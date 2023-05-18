#include "raylib.h"
#include "Game.h"
#include <stdlib.h>

Game::Game()
{

}

void Game::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Duck Hunt");
	SetTargetFPS(60);

	Load();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}

	Unload();
}
void Game::Load() {

}
void Game::Unload() {

}
void Game::Update(float deltaTime) {

	

}
void Game::Draw() {

}


