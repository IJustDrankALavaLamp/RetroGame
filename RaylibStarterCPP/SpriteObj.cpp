#include "SpriteObj.h"
#include "raylib.h"
#include "raygui.h"



SpriteObj::SpriteObj(char filePath[]) {
	image = LoadImage(filePath);
	texture = LoadTextureFromImage(image);
	pos.x = texture.width/2; pos.y = texture.height/2;
}
void SpriteObj::Draw() {

}
void SpriteObj::OnDraw() {

}