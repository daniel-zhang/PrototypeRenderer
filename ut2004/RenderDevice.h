#ifndef RENDER_DEVICE_H
#define RENDER_DEVICE_H

#include "RenderInterface.h"
#include "Viewport.h"

class RenderDevice
{
public:
	RenderInterface mRI;
	RenderInterface* lock(Viewport* pViewport);
	void unlock(RenderInterface* pRI);

};
#endif