
/*
	2016.01.22
	Created by PHJ.
*/

#ifndef _PHS_FRAME_MANAGER_CPP

#define _PHS_FRAME_MANAGER_CPP

#include "PHsFrameManager.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsFrame
	{
		FrameManager::FrameManager()
		{
			GlobalFunctionBinderStdCall <FrameManager, LRESULT, HWND, uInt, WPARAM, LPARAM>::bindClassInstance(this);
			GlobalFunctionBinderStdCall <FrameManager, LRESULT, HWND, uInt, WPARAM, LPARAM>::bindMemberFunc(&FrameManager::frameManagerProc);
		}

		FrameManager::~FrameManager()
		{
			this->destroyFrame();

			GlobalFunctionBinderStdCall <FrameManager, LRESULT, HWND, uInt, WPARAM, LPARAM>::bindClassInstance(nullptr);
			GlobalFunctionBinderStdCall <FrameManager, LRESULT, HWND, uInt, WPARAM, LPARAM>::bindMemberFunc(nullptr);
		}

		Bool FrameManager::createFrame(
			uInt nNewFrameWidth,
			uInt nNewFrameHeight,
			uInt nNewFrameColorBit,
			uInt nNewFrameDepthBit,
			Bool bNewFrameFullscr,
			const std::wstring &sNewFrameClassName,
			const std::wstring &sNewFrameTitleText)
		{
			return this->sOpenGLFrame.initalizeFrame(
			{
				nNewFrameWidth,
				nNewFrameHeight,
				nNewFrameColorBit,
				nNewFrameDepthBit,
				bNewFrameFullscr,
				sNewFrameClassName,
				sNewFrameTitleText,
				&GlobalFunctionBinderStdCall <FrameManager, LRESULT, HWND, uInt, WPARAM, LPARAM>::Function
			});
		}

		Void FrameManager::destroyFrame()
		{
			this->sOpenGLFrame.finalizeFrame();
		}

		LRESULT FrameManager::frameManagerProc(HWND hWnd, uInt nMsg, WPARAM wParam, LPARAM lParam)
		{
			switch(nMsg)
			{
			case WM_MOUSEMOVE:
			{
				Event <PHsEventArgs::MouseMoveEventArg>::callEvent(
				{
					static_cast <Int>(GET_X_LPARAM(lParam)),
					static_cast <Int>(GET_Y_LPARAM(lParam)),
				});
			}
			return 0;
			case WM_LBUTTONUP:
			case WM_LBUTTONDOWN:
			{
				Event <PHsEventArgs::MouseButtonEventArg>::callEvent(
				{
					static_cast <Int>(GET_X_LPARAM(lParam)),
					static_cast <Int>(GET_Y_LPARAM(lParam)),
					PHsEventArgs::MouseButtonEventArg::MouseButton::Button_Left,
					nMsg == WM_LBUTTONDOWN
				});
			}
			return 0;
			case WM_MBUTTONUP:
			case WM_MBUTTONDOWN:
			{
				Event <PHsEventArgs::MouseButtonEventArg>::callEvent(
				{
					static_cast <Int>(GET_X_LPARAM(lParam)),
					static_cast <Int>(GET_Y_LPARAM(lParam)),
					PHsEventArgs::MouseButtonEventArg::MouseButton::Button_Middle,
					nMsg == WM_LBUTTONDOWN
				});
			}
			return 0;
			case WM_RBUTTONUP:
			case WM_RBUTTONDOWN:
			{
				Event <PHsEventArgs::MouseButtonEventArg>::callEvent(
				{
					static_cast <Int>(GET_X_LPARAM(lParam)),
					static_cast <Int>(GET_Y_LPARAM(lParam)),
					PHsEventArgs::MouseButtonEventArg::MouseButton::Button_Right,
					nMsg == WM_LBUTTONDOWN
				});
			}
			return 0;
			case WM_KEYDOWN:
			case WM_KEYUP:
			{
				Event <PHsEventArgs::FrameKeyEventArg>::callEvent(
				{
					static_cast <Byte>(wParam),
					nMsg == WM_KEYDOWN
				});
			}
			return 0;
			case WM_SIZE:
			{
				Event <PHsEventArgs::FrameSizeEventArg>::callEvent(
				{
					static_cast <uInt>(LOWORD(lParam)),
					static_cast <uInt>(HIWORD(lParam))
				});
			}
			return 0;
			case WM_CLOSE:
			{
				Event <PHsEventArgs::FrameCloseEventArg>::callEvent(
				{
					//Empty
				});
			}
			return 0;
			case WM_SYSCOMMAND:
			{
				if(wParam == SC_MONITORPOWER || wParam == SC_SCREENSAVE)
					return 0;
			}
			default:
			return DefWindowProc(hWnd, nMsg, wParam, lParam);
			}
		}
	}
}

#endif