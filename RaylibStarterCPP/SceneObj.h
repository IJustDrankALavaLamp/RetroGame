#pragma once
#include "raylib.h"
#include "raygui.h"
#include <list>
#include <vector>
#include <iterator>
#include <iostream>

class SceneObj
{
public:

	SceneObj();
	SceneObj(char * filePath);
	SceneObj(Vector2 posi);
	SceneObj(char * filePath, Vector2 posi);

	void MoveTo(Vector2 newPos);

	void Draw();
public:
	Vector2 position() { return pos; }
private:
private:
	
	Vector2 pos;
	Texture2D texture;
};

