
#include "raylib.h"

class Game {
public:
	Game();

	void Run();

private:

	void Update(float deltaTime);
	void Draw();

	void Load();
	void Unload();

private:

	int m_windowWidth = 640;
	int m_windowHeight = 480;
};