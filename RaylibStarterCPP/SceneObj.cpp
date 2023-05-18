#include "SceneObj.h"

SceneObj::SceneObj() {

}
SceneObj::~SceneObj() {
	if (parent != nullptr) {
		parent -> RemoveChild(*this);
	}
}

void SceneObj::Draw() {
	
}

void SceneObj::AddChild(SceneObj child) {

	child.parent = this; // sets this SceneObject to the parent of the child

	children.push_back(child); // adds the child to this SceneObjects children list
}
void SceneObj::RemoveChild(SceneObj child) {
	
	if (child.parent == this) {
		child.parent = nullptr;
	}
	children.remove(child); 
}