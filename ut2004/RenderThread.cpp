#include "RenderThread.h"
#include "Viewport.h"

void RenderThread::renderScene()
{
	Viewport* currNodeVp = mCurrNode->mVpCache->mCachedVp; 
	if (currNodeVp->lock())
	{
		mCurrNode->renderCachedData(mCurrNode->mVpCache->mRI);
		mCurrNode->mVpCache->mCachedVp->unlock();
	}

}
