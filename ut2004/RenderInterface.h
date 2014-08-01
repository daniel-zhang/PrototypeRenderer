#ifndef RENDER_INTERFACE_H
#define RENDER_INTERFACE_H

#include "ForwardDecls.h"

class RenderInterface
{
public:
	void setTransform(ETransformType transType, Matrix& matrix);
	void setCullMode(ECullMode cullMode);
	void setWireframe(bool enableWireframe);
};

#endif