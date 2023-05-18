#include "SpriteObj.h"

SpriteObj::SpriteObj(char filePath) {
	image = LoadImage(&filePath);
	texture = LoadTextureFromImage(image);
}