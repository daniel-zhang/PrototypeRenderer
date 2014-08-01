#include "LevelSceneNodeCache.h"

LevelSceneNodeCache::LevelSceneNodeCache()
{
	wtData.litActors = NULL;
	wtData.skinnedMeshes = NULL;
	wtData.useHardwareOcclusion = false;

	mStaticShadowLightsNum = 0;
	mBasePassCompleted = false;
}

LevelSceneNodeCache::LevelSceneNodeCache( LevelSceneNode* inNode)
{
	// Worker thread data 
	wtData.litActors = NULL;
	wtData.skinnedMeshes = NULL;
	wtData.levelSceneNode = inNode;

	wtData.level = inNode->mLevel;
	wtData.model = inNode->mModel;
	
	wtData.worldDPS.translucentDrawList = new TranslucentDrawItemSorter;
	wtData.foregroundDPS.translucentDrawList = new TranslucentDrawItemSorter;

	wtData.useHardwareOcclusion = inNode->enableHardwareOcclusionQuery();
	if (wtData.useHardwareOcclusion)
	{
		wtData.occlusionQueries.reserve(500);
	}

	// Lighting
	mStaticShadowLightsNum = 0;
	mVisbileLightsNum = 0;
	mLightMgr = NULL;

	// Zone
	mZones = 0; 

	// Others
	mSceneNode = inNode;
	mConfig = 0;
	mClient = 0;
	mBasePassCompleted = false;
}

