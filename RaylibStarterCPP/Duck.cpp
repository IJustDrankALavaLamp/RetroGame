#include "Duck.h"

Duck::Duck() {
	char filePath[] = "..\\Images\\Ducked.png";
	pos.x = 200; pos.y = 200;
	Image image = LoadImage(filePath);
	texture = LoadTextureFromImage(image);
}
Duck::Duck(int speed) {

}
Duck::Duck(int speed, Vector2 posi) {

}


bool Duck::isDuck()
{
	return true;
}

void Duck::UpdateObj() {
	pos = Movement();
}

Vector2 Duck::Movement() {
	return Vector2{ 200 , 200};
}