
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _CUSTOM_RUN_H

#define _CUSTOM_RUN_H

/*
	TODO : Place your code here
*/

#include "PHsCommon.h"
#include "PHsEndianness.h"
#include "PHsEntry.h"
#include "PHsEvent.h"
#include "PHsFrameManager.h"
#include "PHsInputManager.h"
#include "PHsMatrix4D.h"
#include "PHsMesh.h"
#include "PHsOpenGLExt.h"
#include "PHsShader.h"
#include "PHsTexture.h"
#include "PHsTextureManager.h"
#include "PHsTimeLine.h"
#include "PHsTransform.h"
#include "PHsVector4D.h"

#include "PHsFrameCloseEventArg.h"
#include "PHsFrameKeyEventArg.h"
#include "PHsFrameSizeEventArg.h"
#include "PHsMouseButtonEventArg.h"
#include "PHsMouseMoveEventArg.h"

#include <algorithm>
#include <Windows.h>

using namespace PHs;

namespace Custom
{
	class CustomRun final :
		public Entry,
		public EventHandler <FrameCloseEventArg>,
		public EventHandler <FrameSizeEventArg>
	{
	private:
		static CustomRun sCustomRun;

	private:
		Bool bFullscr{false};
		Bool bMouseGrab{false};
		Int nLastMousePosX{0};
		Int nLastMousePosY{0};
		Mesh sMesh;
		Shader sShader;
		Transform sCamera;
		Matrix4D sProjection;
		TimeLine sTimeLine;

	private:
		CustomRun() = default;
		CustomRun(CustomRun &&sNewCustomRun) = default;
		CustomRun(const CustomRun &sNewCustomRun) = default;
		~CustomRun() = default;

	public:
		Void createFrame();
		Void destroyFrame();
		Void resetMousePosition();

		virtual Void entryInitialize() override;
		virtual Void entryFinalize() override;
		virtual Void entryFrame() override;

		virtual Void onEvent(const FrameCloseEventArg &sEventArg) override;
		virtual Void onEvent(const FrameSizeEventArg &sEventArg) override;
	};
}

#endif