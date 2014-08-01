#ifndef LEVEL_SCENE_NODE_CACHE_H
#define LEVEL_SCENE_NODE_CACHE_H

#include <list>
#include <vector>

#include "ForwardDecls.h"
#include "LevelSceneNode.h"
#include "SceneNodeCache.h"
#include "DrawPrioritySet.h"
#include "DynamicLight.h"

class DynamicActor;
class SkeletalMeshInstance;
class SceneLightMgr;
class RenderConfig;
class Client;
class ZoneInfo;

struct WorkerThreadData
{
	Level* level;
	Model* model;
	LevelSceneNode* levelSceneNode;

	std::list<levelSceneNode*>* pChildrenNodes;

	// Visible meshes
	DrawPrioritySet						worldDPS;			// World elements
	DrawPrioritySet						foregroundDPS;		// Foreground(UI?) elements

	std::list<DynamicActor*>*			litActors;			// actors with dynamic light support
	std::list<SkeletalMeshInstance*>*	skinnedMeshes;		// visible meshes that require skinning

	bool useHardwareOcclusion;
	std::vector<DynamicActor*> occlusionQueries;
};

class LevelSceneNodeCache : public SceneNodeCache
{
public:
	LevelSceneNodeCache();
	LevelSceneNodeCache(LevelSceneNode* inNode);

	// Game thread writes to wtData while rendering thread consumes it
	// A lock-step is used to sync the two threads
	WorkerThreadData wtData;


	// Lighting
	int mDynamicLightsNum;
	int mStaticShadowLightsNum;
	int mVisbileLightsNum;
	DynamicLight* mDynamicLights[256];
	DynamicLight* mStaticSahdowLights[256];
	DynamicLight* mVisibleLights[256];

	SceneLightMgr* mLightMgr;

	// Render config
	RenderConfig* mConfig;

	// Zone
	ZoneInfo* mZones;
	bool mBasePassCompleted;
	Client* mClient;

};

#endif