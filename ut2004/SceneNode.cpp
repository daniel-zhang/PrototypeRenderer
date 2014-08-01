#include "Viewport.h"
#include "ViewportCache.h"
#include "SceneNodeCache.h"
#include "RenderInterface.h"
#include "RenderTarget.h"

#include "SceneNode.h"


SceneNode::SceneNode( Viewport* vp, RenderTarget* rt )
{
	mParent = NULL;
	mViewport = vp;
	mRenderTarget = rt;

	mRenderCache = NULL;

}

Viewport* SceneNode::getViewport()
{
	return mViewport;
}

void SceneNode::setSceneRenderState( RenderInterface* ri )
{
	ri->setTransform(TT_WorldToCamera, world2cam);
	ri->setTransform(TT_CameraToScreen, cam2screen);
	ri->setCullMode(mCullMode);
	ri->setWireframe(mEnableWireframe);
}
