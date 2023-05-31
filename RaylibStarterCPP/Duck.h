#pragma once
#include "SceneObj.h"
class Duck : public SceneObj
{
private:
	enum direction { right, left, up, expRight, expLeft };
public:
	Duck();
	Duck(int direct);
	Duck(int direct, Vector2 posi);

	bool checkScreen();
	bool isDuck() override;
	void UpdateObj() override;
	void Draw() override;
	
private:
	Vector2 randomPosition();
	
	void randomDirection();

private:
	char filePath[21] = "..\\Images\\Ducked.png";
	void Movement();
	int speed = 5;
	direction dir;
};

