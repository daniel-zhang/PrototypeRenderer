#ifndef VIEWPORT_CACHE_H
#define VIEWPORT_CACHE_H

#include "Viewport.h"
#include "RenderInterface.h"

class ViewportCache
{
public:
	Viewport* mCachedVp;
	RenderInterface* mRI;

	void update(Viewport* vp);
};
#endif