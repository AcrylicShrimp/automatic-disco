
/*
	2016.01.22
	Created by PHJ.
*/

#ifndef _PHS_OPENGL_FRAME_CPP

#define _PHS_OPENGL_FRAME_CPP

#include "PHsOpenGLFrame.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsFrame
	{
		using namespace std;

		Bool OpenGLFrame::initalizeFrame(const OpenGLFrameAttr &sNewOpenGLFrameAttr)
		{
			if(this->bCreated)
				return false;

			WNDCLASS sClass
			{
				CS_OWNDC,															//style
				sNewOpenGLFrameAttr.fWndProc,										//lpfnWndProc
				0,																	//cbClsExtra
				0,																	//cbWndExtra
				this->hFrameInstance = GetModuleHandle(nullptr),					//hInstance
				LoadIcon(nullptr, IDI_APPLICATION),									//hIcon
				LoadCursor(nullptr, IDC_ARROW),										//hCursor
				nullptr,															//hbrBackground
				nullptr,															//lpszMenuName
				(this->sFrameClassName = sNewOpenGLFrameAttr.sClassName).c_str()	//lpszClassName
			};

			if(!RegisterClass(&sClass))
			{
				this->finalizeFrame();
				return false;
			}

			uInt nStyle;
			uInt nExtraStyle;
			RECT sClientRect
			{
				//Empty.
			};

			if(this->bFullscr = sNewOpenGLFrameAttr.bFullscreen)
			{
				nStyle = WS_POPUP;
				nExtraStyle = WS_EX_APPWINDOW;

				GetWindowRect(GetDesktopWindow(), &sClientRect);

				DEVMODE sDevMode
				{
					//Empty.
				};

				sDevMode.dmSize = sizeof(DEVMODE);
				sDevMode.dmPelsWidth = sClientRect.right;
				sDevMode.dmPelsHeight = sClientRect.bottom;
				sDevMode.dmBitsPerPel = sNewOpenGLFrameAttr.nColorBit;
				sDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;

				if(ChangeDisplaySettings(&sDevMode, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
					return this->bFullscr = false;
			}
			else
			{
				nStyle = WS_OVERLAPPEDWINDOW;
				nExtraStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

				sClientRect.right = static_cast <Int>(sNewOpenGLFrameAttr.nWidth);
				sClientRect.bottom = static_cast <Int>(sNewOpenGLFrameAttr.nHeight);
			}

			AdjustWindowRectEx(&sClientRect, nStyle, false, nExtraStyle);

			sClientRect.right -= sClientRect.left;
			sClientRect.bottom -= sClientRect.top;

			if(!(this->hFrameWnd = CreateWindowEx(
				nExtraStyle,
				sNewOpenGLFrameAttr.sClassName.c_str(),
				sNewOpenGLFrameAttr.sTitleText.c_str(),
				nStyle,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				sClientRect.right,
				sClientRect.bottom,
				nullptr,
				nullptr,
				this->hFrameInstance,
				nullptr)))
			{
				this->finalizeFrame();
				return false;
			}

			PIXELFORMATDESCRIPTOR sPixelFormatDesc
			{
				sizeof(PIXELFORMATDESCRIPTOR),
				1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA, static_cast <Byte>(sNewOpenGLFrameAttr.nColorBit),
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, static_cast <Byte>(sNewOpenGLFrameAttr.nDepthBit), 0, 0, PFD_MAIN_PLANE, 0, 0, 0, 0
			};

			if(!(this->hFrameDC = GetDC(this->hFrameWnd)))
			{
				this->finalizeFrame();
				return false;
			}

			Int nPixelFormat = ChoosePixelFormat(this->hFrameDC, &sPixelFormatDesc);
			if(!nPixelFormat)
			{
				this->finalizeFrame();
				return false;
			}

			if(!SetPixelFormat(this->hFrameDC, nPixelFormat, &sPixelFormatDesc))
			{
				this->finalizeFrame();
				return false;
			}

			if(!(this->hFrameRC = wglCreateContext(this->hFrameDC)))
			{
				this->finalizeFrame();
				return false;
			}

			if(!wglMakeCurrent(this->hFrameDC, this->hFrameRC))
			{
				this->finalizeFrame();
				return false;
			}

			SetForegroundWindow(this->hFrameWnd);
			SetFocus(this->hFrameWnd);

			this->bCreated = true;

			/*
				Load OpenGL functions.
			*/
			OpenGLExt::initializeOpenGLExt();

			return true;
		}

		Void OpenGLFrame::finalizeFrame()
		{
			this->bCreated =
				this->bVisible = false;

			if(this->bFullscr)
			{
				ChangeDisplaySettings(nullptr, 0ul);
				this->bFullscr = false;
			}

			if(this->hFrameRC)
			{
				wglMakeCurrent(nullptr, nullptr);
				wglDeleteContext(this->hFrameRC);
			}

			if(this->hFrameWnd)
			{
				if(this->hFrameDC)
					ReleaseDC(this->hFrameWnd, this->hFrameDC);

				DestroyWindow(this->hFrameWnd);
			}

			UnregisterClass(this->sFrameClassName.c_str(), this->hFrameInstance);

			this->hFrameDC = nullptr;
			this->hFrameRC = nullptr;
			this->hFrameWnd = nullptr;
			this->hFrameInstance = nullptr;
		}

		Void OpenGLFrame::setVisible(Bool bNewVisible)
		{
			ShowWindow(this->hFrameWnd, (this->bVisible = bNewVisible) ? SW_SHOW : SW_HIDE);
		}
	}
}

#endif