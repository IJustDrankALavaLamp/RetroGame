#include "SceneObj.h"

class SpriteObj : SceneObj
{
public:
	SpriteObj(char filePath);

private:

	Texture2D texture;
	Image image;
};

