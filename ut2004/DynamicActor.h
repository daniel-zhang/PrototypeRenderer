#ifndef DYNAMIC_ACTOR_H
#define DYNAMIC_ACTOR_H

#include "ForwardDecls.h"
#include "Actor.h"

class AmbientLighting;

struct ActorData
{
};

class DynamicActor
{
public:
	DynamicActor(Actor* inActor);
	Actor* getActor();

	void update(Actor* inActor);
	void updateTransform();

public:
	// CORE DATA ACCESSED BY VISIBILITY SYSTEM. Pack together for cache coherency.
	INT		mRevision;
	INT		mTransformRevision;
	UINT	mUseCullDistance:1;
	UINT	mSkipRendering:1;
	UINT	mForceAlwaysVisible:1;
	Box		mBoundingBox;
	float	mCullDistance;

	// Spatial
	Matrix local2world, world2local;

	// Lighting
	AmbientLighting	mAmbient;

private:
	Actor* mActor;
};
#endif