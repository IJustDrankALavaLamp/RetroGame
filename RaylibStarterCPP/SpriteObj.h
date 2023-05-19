#include "raylib.h"
#include "raygui.h"

class SpriteObj
{
public:
	SpriteObj();
	SpriteObj(char filePath[]);
	~SpriteObj();
	void Draw();

public:

	Texture2D Texture() {
		return texture;
	};

private:
	void OnDraw();

private:

	Vector2 pos;
	Texture2D texture;
	Image image;
};

