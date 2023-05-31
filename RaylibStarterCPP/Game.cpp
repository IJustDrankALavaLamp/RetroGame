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
	char dir[] = "..\\Images\\Background.png";
	background = SceneObj(dir, middle);
	char dirr[] = "..\\Images\\CrossHair.png";
	shot = SceneObj{ dirr, Vector2{-10,-10} };
	char dirrr[] = "..\\Images\\Grass.png";
	foreground = SceneObj{ dirrr, middle };

}
void Game::Unload() {

}

void Game::Update(float deltaTime) {
	timer -= deltaTime;
	if (Objs.size() < 25) {
		spawnDuck();
	}
	for (size_t i = 0; i < Objs.size(); i++)
	{
		Objs[i].UpdateObj();
		if (!Objs[i].checkScreen()) {
			Objs.erase(Objs.begin() + i);
			i--;
		}
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		Vector2 mousepos = GetMousePosition();
		timer = 1;
		Shoot(mousepos);
	}
	else if (IsKeyPressed(KEY_R)) {

	}
	if (timer <= 0 && (shot.position().x != -10 || shot.position().y != -10)) {
		shot.MoveTo(Vector2{ -10,-10 });
	}

}

void Game::spawnDuck() {

	Duck newDuck = Duck();

	Objs.push_back(newDuck);
}

void Game::Shoot(Vector2 mousePos) {
	Vector2 posi = Vector2{ mousePos.x, mousePos.y };
	shot.MoveTo(posi);

	for (size_t i = 0; i < Objs.size(); i++) {
		if (shot.isCollide(Objs[i].position())) {
			Objs.erase(Objs.begin() + i);
			i--;
		}
	}

}

void Game::Draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);

	background.Draw();
	for (size_t i = 0; i < Objs.size(); i++)
	{
		Objs[i].Draw();
	}
	foreground.Draw();
	shot.Draw();
	EndDrawing();
}


