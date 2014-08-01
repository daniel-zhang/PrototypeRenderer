#include "LevelSceneNode.h"
#include "LevelSceneNodeCache.h"

void LevelSceneNode::cacheRendering()
{
	if (!mRenderCache)
	{
		mRenderCache = new LevelSceneNodeCache(this);
	}
	LevelSceneNodeCache* lCache = reinterpret_cast<LevelSceneNodeCache*>(mRenderCache);

	mViewportCache->update(this->getViewport());

	if (this->mParent == NULL)
		lCache->setupActors();
	else
		lCache->inheritSetupActors((LevelSceneNodeCache*)this->mParent->mRenderCache);

	lCache->setupViewFrustum();
	lCache->calcVisibility();
	lCache->buildDrawList();

}

void LevelSceneNode::renderCachedData( RenderInterface* ri, bool isMt )
{

}

void LevelSceneNode::render( RenderInterface* ri )
{

}
