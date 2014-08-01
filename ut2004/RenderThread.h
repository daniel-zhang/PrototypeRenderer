#ifndef RENDER_THREAD_H
#define RENDER_THREAD_H

#include "ForwardDecls.h"
#include "LevelSceneNode.h"

class RenderThread
{
public:
	void renderScene();

private:
	LevelSceneNode* mCurrNode;
};
#endif