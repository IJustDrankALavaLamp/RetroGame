#include "Duck.h"

Duck::Duck() {
	randomDirection();
	pos = randomPosition();
	Image image = LoadImage(filePath);
	texture = LoadTextureFromImage(image);
}
Duck::Duck(int direct) {
	switch (direct) {
	case 0:
		dir = right;
		break;
	case 1:
		dir = left;
		break;
	case 2:
		dir = up;
		break;
	case 3:
		dir = expRight;
		break;
	case 4:
		dir = expLeft;
		break;
	default:
		dir = right;
		break;
	}
	pos = Vector2{ 0, 200 };
	Image image = LoadImage(filePath);
	texture = LoadTextureFromImage(image);
}
Duck::Duck(int direct, Vector2 posi) {
	switch (direct) {
	case 0:
		dir = right;
		break;
	case 1:
		dir = left;
		break;
	case 2:
		dir = up;
		break;
	case 3:
		dir = expRight;
		break;
	case 4:
		dir = expLeft;
		break;
	default:
		dir = right;
		break;
	}
	pos = posi;
	Image image = LoadImage(filePath);
	texture = LoadTextureFromImage(image);
}

void Duck::Draw() {
	Rectangle source{ 0, 0, (dir == right || dir == expRight ? -1 : 1) * (float)texture.width, (float)texture.height }; // how much of the image from top left

	Rectangle position{ (float)pos.x, (float)pos.y, (float)texture.width, (float)texture.height }; // scale of image
	Vector2 origin{ (float)(texture.width / 2), (float)(texture.height / 2) }; // where to draw from
	DrawTexturePro(texture,
		source, position, origin,
		0, WHITE);
}

Vector2 Duck::randomPosition() {

	return Vector2{ 200, 200 };
}
void Duck::randomDirection() {
	int k = std::rand() % 5;
	switch (k) {
	case 0:
		dir = right;
		break;
	case 1:
		dir = left;
		break;
	case 2:
		dir = up;
		break;
	case 3:
		dir = expRight;
			break;
	case 4:
		dir = expLeft;
		break;
	}
}


bool Duck::isDuck()
{
	return true;
}

void Duck::UpdateObj() {
	Movement();
}

void Duck::Movement() {
	Vector2 newPos = pos;

	switch(dir){
	case right:
		newPos = Vector2{ newPos.x + speed, newPos.y };
		break;
	case left:
		newPos = Vector2{ newPos.x - speed, newPos.y };
		break;
	case up:
		newPos = Vector2{newPos.x, newPos.y - speed};
		break;
	case expLeft:
		int x = 0, y = 0;
		newPos = Vector2{};
		break;
	case expRight:

		break;
	}
	pos = newPos;
}