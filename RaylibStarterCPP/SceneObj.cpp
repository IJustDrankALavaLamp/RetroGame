#include "SceneObj.h"

SceneObj::SceneObj() {
	pos.x = 0; pos.y = 0;
}
SceneObj::SceneObj(char image[]) {
	SpriteObj sprit = SpriteObj(image);
	sprite = sprit;
}
SceneObj::~SceneObj() {
	if (parent != nullptr) {
		parent -> RemoveChild(*this);
	}
}

void SceneObj::Draw() {
	if (sprite.Texture().id <= 0) {
		OnDraw();
	}
}
void SceneObj::OnDraw() {
	sprite.Draw();
}

void SceneObj::AddChild(SceneObj child) {

	child.parent = this; // sets this SceneObject to the parent of the child

	children.add(child); // adds the child to this SceneObjects children list
}
void SceneObj::RemoveChild(SceneObj child) {
	
	if (child.parent == this) {
		child.parent = nullptr;
	}
	children.remove(child); 
}