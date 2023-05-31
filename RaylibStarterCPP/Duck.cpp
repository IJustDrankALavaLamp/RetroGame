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
	float x = 0; float y = 0;
	switch (dir) {
	case right:
		x = -10;
		y = (std::rand() % 400) + 10;
			break;
		case left:
			x = GetScreenWidth() + 10;
			y = (std::rand() % 400) + 10;
			break;
		case up:
			x = std::rand() % GetScreenWidth();
			y = GetScreenHeight() + 10;
			break;
		case expLeft:
			x = std::rand() % GetScreenWidth();
			y = GetScreenHeight() + 10;
			break;
		case expRight:
			x = std::rand() % GetScreenWidth();
			y = GetScreenHeight() + 10;
			break;
		default:

			break;
	}
	return Vector2{ x, y };
}
void Duck::randomDirection() {
	int k = std::rand() % 5;
	switch (k) {
	case 0:
		dir = right;
		std::cout << "right\n";
		break;
	case 1:
		dir = left;
		std::cout << "left\n";
		break;
	case 2:
		dir = up;
		std::cout << "up\n";
		break;
	case 3:
		dir = expRight;
		std::cout << "expRight\n";
		break;
	case 4:
		dir = expLeft;
		std::cout << "expLeft\n";
		break;
	default:
		dir = up;
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

bool Duck::checkScreen() {
	switch (dir) {
	case right:
		if (pos.x == GetScreenWidth() + 10) {
			return false;
		}
		break;
	case left:
		if (pos.x == -10) return false;
		break;
	case up:
		if (pos.y == -10) return false;
		break;
	case expLeft:
		if (pos.x == -10 || pos.y == -10) return false;
		break;
	case expRight:
		if (pos.x == GetScreenWidth() + 10 || pos.y == -10) return false;
		break;
	}
	return true;
}

void Duck::Movement() {
	Vector2 newPos = pos;
	float x, y;
	switch (dir) {
	case right:
		newPos = Vector2{ newPos.x + speed, newPos.y };

		break;
	case left:
		newPos = Vector2{ newPos.x - speed, newPos.y };

		break;
	case up:
		newPos = Vector2{ newPos.x, newPos.y - speed };

		break;
	case expLeft:
		newPos.x -= speed;  newPos.y -= speed;
		break;
	case expRight:
		newPos.x += speed;  newPos.y -= speed;
		break;
	default:
		newPos = Vector2{ newPos.x, newPos.y - speed };
		std::cout << "default\n";
		break;
	}

	pos = newPos;
}