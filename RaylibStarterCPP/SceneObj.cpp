#include "SceneObj.h"


SceneObj::SceneObj() {
	pos.x = 0; pos.y = 0;
}
SceneObj::SceneObj(char * filePath) {
	pos.x = 0; pos.y = 0;
	Image image = LoadImage(filePath);
	texture = LoadTextureFromImage(image);
}
SceneObj::SceneObj(Vector2 posi) {
	pos.x = posi.x;
	pos.y = posi.y;
	
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

/// <summary>
/// Draw Object
/// </summary>
void SceneObj::Draw() {

	Rectangle source{ 0, 0, texture.width, texture.height }; // how much of the image from top left
	Rectangle position{ pos.x, pos.y, texture.width, texture.height }; // scale of image
	Vector2 origin{ texture.width / 2, texture.height / 2 }; // where to draw from
	DrawTexturePro(texture,
		source, position, origin,
		0, WHITE);
}
void SceneObj::MoveTo(Vector2 newPos) {
	pos = newPos;
	std::cout << "x: " << pos.x << " y: " << pos.y << "\n";
}
