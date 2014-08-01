#ifndef LEVEL_SCENE_NODE_H
#define LEVEL_SCENE_NODE_H

#include "ForwardDecls.h"
#include "SceneNode.h"

class LevelSceneNode : public SceneNode
{
public:
	LevelSceneNode();

	virtual void cacheRendering(); // Game thread: generate rendering states and put them into render cache
	virtual void renderCachedData(RenderInterface* ri, bool isMt); // Rendering thread: render the generated states from render cache
	void render(RenderInterface* ri); // cache and render in one step

	// Sub-interfaces mask
	virtual LevelSceneNode* getLevelSceneNode(){return this;}

	// Other state queries
	bool enableHardwareOcclusionQuery();

public:
	Level* mLevel;
	Model* mModel;
	Actor* mActor;


private:
};
#endif