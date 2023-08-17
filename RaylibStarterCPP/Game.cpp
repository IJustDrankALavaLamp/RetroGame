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
	ammo = max_Ammo;


}

void Game::Unload() {

}

void Game::Update(float deltaTime) {
	timer -= deltaTime;
	reloadTime -= deltaTime;
	if (Objs.size() < 20 && count > 31) {
		spawnDuck();
		count = 0;
	}
	else { count++; }
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
		reloading = true;
		reloadTime = 2;
	}
	if (timer <= 0 && (shot.position().x != -10 || shot.position().y != -10)) {
		shot.MoveTo(Vector2{ -10,-10 });
	}
	if (reloading && reloadTime < 0) {
		ammo = max_Ammo;
		reloading = false;
	}

}

void Game::spawnDuck() {

	Duck newDuck = Duck();

	Objs.push_back(newDuck);
}

void Game::Shoot(Vector2 mousePos) {
	if (ammo > 0 && reloading == false) {
		Vector2 posi = Vector2{ mousePos.x, mousePos.y };
		ammo--;
		shot.MoveTo(posi);

		for (size_t i = 0; i < Objs.size(); i++) {
			if (shot.isCollide(Objs[i].position())) {
				Objs.erase(Objs.begin() + i);
				score += 10;
				i--;
			}
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

	DrawText(TextFormat("Score: %i", (int)score), 20, (m_windowHeight - 50), 20, BLACK);
	DrawText(TextFormat("Ammo: %i/5", (int)ammo),(m_windowWidth - 150), (m_windowHeight - 50), 20, BLACK);
	if (ammo == 0 && reloading == false) {
		DrawText("Press 'R' to Reload", (20), (10), 40, RED);
	}
	else if (reloading == true) {
		DrawText("Reloading...", (20), (10), 40, RED);
	}

	EndDrawing();
}