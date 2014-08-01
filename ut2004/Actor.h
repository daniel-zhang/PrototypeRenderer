#ifndef ACTOR_H
#define ACTOR_H

#include "ForwardDecls.h"
#include "DynamicActor.h"
#include "DynamicLight.h"
#include "StaticMesh.h"
#include "Material.h"

class Actor
{
public:
	bool refreshActorRenderData()
	{
		if (mActorRenderData == NULL)
			mActorRenderData = new DynamicActor(this);

		if (mActorRenderData->mRevision != mRenderRevision)
			return  updateRenderData();
		else
			return updateRenderData(true);
	}

	bool updateRenderData(bool fullUpdate)
	{
		if (fullUpdate)
			mActorRenderData->update(this);
		else
			mActorRenderData->updateTransform();
	}

public:
	DynamicActor* mActorRenderData;
	DynamicLight* mLightRenderData;

	StaticMesh* mStaticMesh;
	Vector mPosition;
	Rotator mRotation;

	INT mRenderRevision;
	
};
#endif