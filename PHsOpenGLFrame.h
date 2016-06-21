
/*
	2016.01.22
	Created by PHJ.
*/

#ifndef _PHS_OPENGL_FRAME_H

#define _PHS_OPENGL_FRAME_H

#include "PHsCommon.h"
#include "PHsOpenGLExt.h"

#include <string>
#include <Windows.h>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsFrame
	{
		using OpenGLFrameAttr = struct __OpenGL_Frame_Attribute
		{
		public:
			uInt nWidth;
			uInt nHeight;
			uInt nColorBit;
			uInt nDepthBit;
			Bool bFullscreen;
			std::wstring sClassName;
			std::wstring sTitleText;
			WNDPROC fWndProc;
		};

		class OpenGLFrame final
		{
		private:
			HDC hFrameDC{nullptr};
			HGLRC hFrameRC{nullptr};
			HWND hFrameWnd{nullptr};
			HINSTANCE hFrameInstance{nullptr};
			std::wstring sFrameClassName;
			Bool bCreated{false};
			Bool bVisible{false};
			Bool bFullscr{false};

		public:
			OpenGLFrame() = default;
			OpenGLFrame(OpenGLFrame &&sNewOpenGLFrame) = default;
			OpenGLFrame(const OpenGLFrame &sOpenGLFrame) = delete;
			inline ~OpenGLFrame();

		public:
			inline OpenGLFrame &operator=(OpenGLFrame &&sNewOpenGLFrame) = default;
			inline OpenGLFrame &operator=(const OpenGLFrame &sOpenGLFrame) = delete;
			inline HDC frameDC() const;
			inline HGLRC frameRC() const;
			inline HWND frameWnd() const;
			inline HINSTANCE frameInstance() const;

			Bool initalizeFrame(const OpenGLFrameAttr &sNewOpenGLFrameAttr);
			Void finalizeFrame();
			Void setVisible(Bool bNewVisible);
		};

		inline OpenGLFrame::~OpenGLFrame()
		{
			this->finalizeFrame();
		}

		inline HDC OpenGLFrame::frameDC() const
		{
			return this->hFrameDC;
		}

		inline HGLRC OpenGLFrame::frameRC() const
		{
			return this->hFrameRC;
		}

		inline HWND OpenGLFrame::frameWnd() const
		{
			return this->hFrameWnd;
		}

		inline HINSTANCE OpenGLFrame::frameInstance() const
		{
			return this->hFrameInstance;
		}
	}
}

#endif