#ifndef VIEW_PORT_H
#define VIEW_PORT_H

#include "RenderDevice.h"
#include "RenderInterface.h"

class Viewport
{
public:
	bool lock();
	void unlock();

	RenderDevice* mRD;
	RenderInterface* mRI;
};
#endif