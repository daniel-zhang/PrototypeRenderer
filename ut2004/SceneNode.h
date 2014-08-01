#ifndef SCENE_NODE_H
#define SCENE_NODE_H

#include "ForwardDecls.h"

class Viewport;
class ViewportCache;
class SceneNodeCache;
class RenderInterface;
class RenderTarget;
class LevelSceneNode;

class SceneNode
{
public:
	SceneNode(Viewport* vp, RenderTarget* rt);

	// Rendering
	Viewport* getViewport();
	virtual void cacheRendering() = 0;
	virtual void renderCachedData(RenderInterface* ri, bool isMt) = 0;
	virtual void setSceneRenderState(RenderInterface* ri);

	// Sub-interfaces mask
	virtual LevelSceneNode* getLevelSceneNode(){return NULL;}

public:
	SceneNode* mParent;
	RenderTarget* mRenderTarget;

	/// <summary>
	/// Rendering data structures
	/// </summary>
	SceneNodeCache* mRenderCache;	// Cache render state
	ViewportCache* mViewportCache;

	// Spatial
	Matrix world2cam, cam2world;
	Matrix cam2screen, screen2cam;
	Matrix world2screen, screen2world;

	// Graphic enumerations
	ECullMode mCullMode;
	bool mEnableWireframe;

private:
	Viewport* mViewport;
};

#endif