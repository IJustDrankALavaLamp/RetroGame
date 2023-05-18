#include "raylib.h"
#include "raygui.h"
#include <list>
class SceneObj
{
public:

	SceneObj();
	~SceneObj();
	void Draw();

	void AddChild(SceneObj child);
	void RemoveChild(SceneObj child);

public:

	SceneObj* parent = nullptr;

private:



private:
	std::list<SceneObj> children;
};

