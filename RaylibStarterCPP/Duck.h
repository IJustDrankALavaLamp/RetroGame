#pragma once
#include "SceneObj.h"
class Duck : public SceneObj
{
public:
	Duck();
	Duck(int speed);
	Duck(int speed, Vector2 posi);

	bool isDuck() override;
	void UpdateObj() override;


private:
	Vector2 Movement();

};

