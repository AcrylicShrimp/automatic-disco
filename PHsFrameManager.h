
/*
	2016.01.22
	Created by PHJ.
*/

#ifndef _PHS_FRAME_MANAGER_H

#define _PHS_FRAME_MANAGER_H

#include "PHsCommon.h"
#include "PHsEvent.h"
#include "PHsGlobalFunctionBinder.h"
#include "PHsManagerBase.h"
#include "PHsOpenGLFrame.h"

#include "PHsFrameCloseEventArg.h"
#include "PHsFrameKeyEventArg.h"
#include "PHsFrameSizeEventArg.h"
#include "PHsMouseButtonEventArg.h"
#include "PHsMouseMoveEventArg.h"

#include <string>
#include <Windows.h>
#include <windowsx.h>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsFrame
	{
		class FrameManager final : public ManagerBase <FrameManager>
		{
		public:
			friend ManagerBase <FrameManager>;

		private:
			OpenGLFrame sOpenGLFrame;

		private:
			FrameManager();
			FrameManager(FrameManager &&sNewFrameManager) = delete;
			FrameManager(const FrameManager &sNewFrameManager) = delete;
			~FrameManager();

		public:
			FrameManager &operator=(FrameManager &&sNewFrameManager) = delete;
			FrameManager &operator=(const FrameManager &sNewFrameManager) = delete;

			inline OpenGLFrame &framemanagerFrame();

			Bool createFrame(
				uInt nNewFrameWidth,
				uInt nNewFrameHeight,
				uInt nNewFrameColorBit,
				uInt nNewFrameDepthBit,
				Bool bNewFrameFullscr,
				const std::wstring &sNewFrameClassName,
				const std::wstring &sNewFrameTitleText);
			Void destroyFrame();

		private:
			LRESULT frameManagerProc(HWND hWnd, uInt nMsg, WPARAM wParam, LPARAM lParam);
		};

		inline OpenGLFrame &FrameManager::framemanagerFrame()
		{
			return this->sOpenGLFrame;
		}
	}
}

#endif