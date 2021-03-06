#ifndef GRAPHIC_ENUMS_H
#define GRAPHIC_ENUMS_H

enum ECullMode
{
	CM_CW,
	CM_CCW,
	CM_None
};

enum ETransformType
{
	TT_LocalToWorld,
	TT_WorldToCamera,
	TT_CameraToScreen
};

enum EScenePass
{
	SP_Solid,			// rendering solid parts of scene
	SP_Translucent,		// rendering translucent parts of scene
};

#endif