#include "Game.h"
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
	time_t t;
	srand((unsigned)time(&t));

	SceneObj bkgrnd = SceneObj();
}
void Game::Unload() {

}

void Game::Update(float deltaTime) {
	
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		Vector2 mousepos = GetMousePosition();
		
		Shoot(mousepos);
	}
	else if (IsKeyPressed(KEY_R)) {

	}
	
}

void Game::Shoot(Vector2 mousePos) {
	std::cout << "x: " << mousePos.x << " y: " << mousePos.y << "\n";
}

void Game::Draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);


	EndDrawing();
}


