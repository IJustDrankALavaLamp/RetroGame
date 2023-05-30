#pragma once
#include "raylib.h"
#include "raygui.h"
#include <vector>

#include <iostream>

class SceneObj
{
public:

	SceneObj();
	SceneObj(char * filePath);
	SceneObj(Vector2 posi);
	SceneObj(char * filePath, Vector2 posi);

	
	virtual bool isDuck();
	virtual void UpdateObj();
	
	bool isCollide(Vector2 other);
	void MoveTo(Vector2 newPos);
	virtual void Draw();
public:
	Vector2 position() { return pos; }

protected:
	
	Vector2 pos;
	Texture2D texture;
};

