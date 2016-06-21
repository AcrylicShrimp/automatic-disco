
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _PHS_OPENGL_EXT_H

#define _PHS_OPENGL_EXT_H

#include "PHsCommon.h"

#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <gl\glext.h>
#include <gl\wglext.h>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		class OpenGLExt final
		{
		public:
			static PFNGLGENBUFFERSPROC glGenBuffers;
			static PFNGLBINDBUFFERPROC glBindBuffer;
			static PFNGLBUFFERDATAPROC glBufferData;
			static PFNGLMAPBUFFERPROC glMapBuffer;
			static PFNGLUNMAPBUFFERPROC glUnmapBuffer;
			static PFNGLDELETEBUFFERSPROC glDeleteBuffers;
			static PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
			static PFNGLCREATESHADERPROC glCreateShader;
			static PFNGLDELETESHADERPROC glDeleteShader;
			static PFNGLSHADERSOURCEPROC glShaderSource;
			static PFNGLCOMPILESHADERPROC glCompileShader;
			static PFNGLCREATEPROGRAMPROC glCreateProgram;
			static PFNGLDELETEPROGRAMPROC glDeleteProgram;
			static PFNGLATTACHSHADERPROC glAttachShader;
			static PFNGLDETACHSHADERPROC glDetachShader;
			static PFNGLLINKPROGRAMPROC glLinkProgram;
			static PFNGLUSEPROGRAMPROC glUseProgram;
			static PFNGLVALIDATEPROGRAMPROC glValidateProgram;
			static PFNGLGETINFOLOGARBPROC glGetInfoLogARB;
			static PFNGLACTIVETEXTUREPROC glActiveTexture;
			static PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
			static PFNGLUNIFORM1IPROC glUniform1i;
			static PFNGLUNIFORM1FPROC glUniform1f;
			static PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
			static PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
			static PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
			static PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
			static PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
			static PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
			static PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
			static PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
			static PFNGLDRAWBUFFERSPROC glDrawBuffers;
			static PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
			static PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
			static PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv;
			static PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv;
			static PFNGLUNIFORM3FVPROC glUniform3fv;
			static PFNGLUNIFORM4FVPROC glUniform4fv;
			static PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
			static PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
			static PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
			static PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
			static PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
			static PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
			static PFNGLUNIFORM2FVPROC glUniform2fv;
			static PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
			static PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
			static PFNGLUNIFORM1UIPROC glUniform1ui;
			static PFNGLUNIFORM1FVPROC glUniform1fv;
			static PFNGLUNIFORM1IVPROC glUniform1iv;
			static PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
			static PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
			static PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
			static PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
			static PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;

		public:
			static Void initializeOpenGLExt();

		private:
			OpenGLExt() = delete;
			OpenGLExt(OpenGLExt &&sNewOpenGLExt) = delete;
			OpenGLExt(const OpenGLExt &sNewOpenGLExt) = delete;
			~OpenGLExt() = delete;
		};
	}
}

#endif