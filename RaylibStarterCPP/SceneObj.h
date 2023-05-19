#include "raylib.h"
#include "raygui.h"

#include "SpriteObj.h"
#include "ObjList.h"
class SceneObj
{
public:

	SceneObj();
	SceneObj(char image[]);
	~SceneObj();
	 void Draw();


	 void AddChild(SceneObj child);
	 void RemoveChild(SceneObj child);

public:

	SceneObj* parent = nullptr;
private:
	void OnDraw();
private:
	Vector2 pos;
	ObjList children;
	SpriteObj sprite;
};

