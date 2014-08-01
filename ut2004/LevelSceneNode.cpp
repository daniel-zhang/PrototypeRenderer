#include "LevelSceneNode.h"
#include "LevelSceneNodeCache.h"

void LevelSceneNode::cacheRendering()
{
	if (!mRenderCache)
	{
		mRenderCache = new LevelSceneNodeCache(this);
	}
	LevelSceneNodeCache* lCache = reinterpret_cast<LevelSceneNodeCache*>(mRenderCache);

}

void LevelSceneNode::renderCachedData( RenderInterface* ri, bool isMt )
{

}

void LevelSceneNode::render( RenderInterface* ri )
{

}
