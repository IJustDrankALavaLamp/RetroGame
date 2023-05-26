#include "SceneObj.h"


SceneObj::SceneObj() {
	pos.x = 0; pos.y = 0;
	texture = Texture2D{};
}
SceneObj::SceneObj(char * filePath) {
	pos.x = 0; pos.y = 0;
	Image image = LoadImage(filePath);
	texture = LoadTextureFromImage(image);
}
SceneObj::SceneObj(Vector2 posi) {
	pos.x = posi.x;
	pos.y = posi.y;
	texture = Texture2D{};
}
SceneObj::SceneObj(char* filePath, Vector2 posi) {
	pos.x = posi.x; pos.y = posi.y;
	Image image = LoadImage(filePath);
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
}

bool SceneObj::isDuck() { return false; }

void SceneObj::UpdateObj() {
}
bool SceneObj::isCollide(Vector2 other) {
	Vector2 minS = Vector2{ pos.x - (texture.width), pos.y - (texture.height)};
	Vector2 maxS = Vector2{pos.x + (texture.width), pos.y + (texture.height) };
	
	if ((other.x > minS.x && other.y > minS.y) && (other.x < maxS.x && other.y < maxS.y)) {
		std::cout << "true" << "\n";
		return true;
	}
	else
		std::cout << "false" << "\n";
		return false;
}

void SceneObj::MoveTo(Vector2 newPos) {
	pos = newPos;
	std::cout << "x: " << pos.x << " y: " << pos.y << "\n";
}

/// <summary>
/// Draw Object
/// </summary>
void SceneObj::Draw() {

	Rectangle source{ 0, 0, (float)texture.width, (float)texture.height }; // how much of the image from top left
	Rectangle position{ (float)pos.x, (float)pos.y, (float)texture.width, (float)texture.height }; // scale of image
	Vector2 origin{ (float)(texture.width / 2), (float)(texture.height / 2) }; // where to draw from
	DrawTexturePro(texture,
		source, position, origin,
		0, WHITE);
}

