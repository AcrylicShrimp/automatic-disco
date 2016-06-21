
/*
	2016.01.26
	Created by PHJ.
*/

#ifndef _PHS_OPENGL_EXT_CPP

#define _PHS_OPENGL_EXT_CPP

#include "PHsOpenGLExt.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		PFNGLGENBUFFERSPROC OpenGLExt::glGenBuffers = nullptr;
		PFNGLBINDBUFFERPROC OpenGLExt::glBindBuffer = nullptr;
		PFNGLBUFFERDATAPROC OpenGLExt::glBufferData = nullptr;
		PFNGLMAPBUFFERPROC OpenGLExt::glMapBuffer = nullptr;
		PFNGLUNMAPBUFFERPROC OpenGLExt::glUnmapBuffer = nullptr;
		PFNGLDELETEBUFFERSPROC OpenGLExt::glDeleteBuffers = nullptr;
		PFNWGLSWAPINTERVALEXTPROC OpenGLExt::wglSwapIntervalEXT = nullptr;
		PFNGLCREATESHADERPROC OpenGLExt::glCreateShader = nullptr;
		PFNGLDELETESHADERPROC OpenGLExt::glDeleteShader = nullptr;
		PFNGLSHADERSOURCEPROC OpenGLExt::glShaderSource = nullptr;
		PFNGLCOMPILESHADERPROC OpenGLExt::glCompileShader = nullptr;
		PFNGLCREATEPROGRAMPROC OpenGLExt::glCreateProgram = nullptr;
		PFNGLDELETEPROGRAMPROC OpenGLExt::glDeleteProgram = nullptr;
		PFNGLATTACHSHADERPROC OpenGLExt::glAttachShader = nullptr;
		PFNGLDETACHSHADERPROC OpenGLExt::glDetachShader = nullptr;
		PFNGLLINKPROGRAMPROC OpenGLExt::glLinkProgram = nullptr;
		PFNGLUSEPROGRAMPROC OpenGLExt::glUseProgram = nullptr;
		PFNGLVALIDATEPROGRAMPROC OpenGLExt::glValidateProgram = nullptr;
		PFNGLGETINFOLOGARBPROC OpenGLExt::glGetInfoLogARB = nullptr;
		PFNGLACTIVETEXTUREPROC OpenGLExt::glActiveTexture = nullptr;
		PFNGLGETUNIFORMLOCATIONPROC OpenGLExt::glGetUniformLocation = nullptr;
		PFNGLUNIFORM1IPROC OpenGLExt::glUniform1i = nullptr;
		PFNGLUNIFORM1FPROC OpenGLExt::glUniform1f = nullptr;
		PFNGLGENFRAMEBUFFERSPROC OpenGLExt::glGenFramebuffers = nullptr;
		PFNGLGENRENDERBUFFERSPROC OpenGLExt::glGenRenderbuffers = nullptr;
		PFNGLBINDRENDERBUFFERPROC OpenGLExt::glBindRenderbuffer = nullptr;
		PFNGLRENDERBUFFERSTORAGEPROC OpenGLExt::glRenderbufferStorage = nullptr;
		PFNGLBINDFRAMEBUFFERPROC OpenGLExt::glBindFramebuffer = nullptr;
		PFNGLFRAMEBUFFERTEXTURE2DPROC OpenGLExt::glFramebufferTexture2D = nullptr;
		PFNGLDELETEFRAMEBUFFERSPROC OpenGLExt::glDeleteFramebuffers = nullptr;
		PFNGLDELETERENDERBUFFERSPROC OpenGLExt::glDeleteRenderbuffers = nullptr;
		PFNGLDRAWBUFFERSPROC OpenGLExt::glDrawBuffers = nullptr;
		PFNGLCHECKFRAMEBUFFERSTATUSPROC OpenGLExt::glCheckFramebufferStatus = nullptr;
		PFNGLBINDATTRIBLOCATIONPROC OpenGLExt::glBindAttribLocation = nullptr;
		PFNGLVERTEXATTRIB2FVPROC OpenGLExt::glVertexAttrib2fv = nullptr;
		PFNGLVERTEXATTRIB3FVPROC OpenGLExt::glVertexAttrib3fv = nullptr;
		PFNGLUNIFORM3FVPROC OpenGLExt::glUniform3fv = nullptr;
		PFNGLUNIFORM4FVPROC OpenGLExt::glUniform4fv = nullptr;
		PFNGLUNIFORMMATRIX4FVPROC OpenGLExt::glUniformMatrix4fv = nullptr;
		PFNGLENABLEVERTEXATTRIBARRAYPROC OpenGLExt::glEnableVertexAttribArray = nullptr;
		PFNGLDISABLEVERTEXATTRIBARRAYPROC OpenGLExt::glDisableVertexAttribArray = nullptr;
		PFNGLDRAWELEMENTSINSTANCEDPROC OpenGLExt::glDrawElementsInstanced = nullptr;
		PFNGLVERTEXATTRIBDIVISORPROC OpenGLExt::glVertexAttribDivisor = nullptr;
		PFNGLVERTEXATTRIBPOINTERPROC OpenGLExt::glVertexAttribPointer = nullptr;
		PFNGLUNIFORM2FVPROC OpenGLExt::glUniform2fv = nullptr;
		PFNGLUNIFORMMATRIX2FVPROC OpenGLExt::glUniformMatrix2fv = nullptr;
		PFNGLUNIFORMMATRIX3FVPROC OpenGLExt::glUniformMatrix3fv = nullptr;
		PFNGLUNIFORM1UIPROC OpenGLExt::glUniform1ui = nullptr;
		PFNGLUNIFORM1FVPROC OpenGLExt::glUniform1fv = nullptr;
		PFNGLUNIFORM1IVPROC OpenGLExt::glUniform1iv = nullptr;
		PFNGLGENVERTEXARRAYSPROC OpenGLExt::glGenVertexArrays = nullptr;
		PFNGLDELETEVERTEXARRAYSPROC OpenGLExt::glDeleteVertexArrays = nullptr;
		PFNGLBINDVERTEXARRAYPROC OpenGLExt::glBindVertexArray = nullptr;
		PFNGLGENERATEMIPMAPPROC OpenGLExt::glGenerateMipmap = nullptr;
		PFNGLGETSHADERINFOLOGPROC OpenGLExt::glGetShaderInfoLog = nullptr;

		Void OpenGLExt::initializeOpenGLExt()
		{
			OpenGLExt::glGenBuffers = reinterpret_cast <PFNGLGENBUFFERSPROC>(wglGetProcAddress("glGenBuffers"));
			OpenGLExt::glBindBuffer = reinterpret_cast <PFNGLBINDBUFFERPROC>(wglGetProcAddress("glBindBuffer"));
			OpenGLExt::glBufferData = reinterpret_cast <PFNGLBUFFERDATAPROC>(wglGetProcAddress("glBufferData"));
			OpenGLExt::glMapBuffer = reinterpret_cast <PFNGLMAPBUFFERPROC>(wglGetProcAddress("glMapBuffer"));
			OpenGLExt::glUnmapBuffer = reinterpret_cast <PFNGLUNMAPBUFFERPROC>(wglGetProcAddress("glUnmapBuffer"));
			OpenGLExt::glDeleteBuffers = reinterpret_cast <PFNGLDELETEBUFFERSPROC>(wglGetProcAddress("glDeleteBuffers"));
			OpenGLExt::wglSwapIntervalEXT = reinterpret_cast <PFNWGLSWAPINTERVALEXTPROC>(wglGetProcAddress("wglSwapIntervalEXT"));
			OpenGLExt::glCreateShader = reinterpret_cast <PFNGLCREATESHADERPROC>(wglGetProcAddress("glCreateShader"));
			OpenGLExt::glDeleteShader = reinterpret_cast <PFNGLDELETESHADERPROC>(wglGetProcAddress("glDeleteShader"));
			OpenGLExt::glShaderSource = reinterpret_cast <PFNGLSHADERSOURCEPROC>(wglGetProcAddress("glShaderSource"));
			OpenGLExt::glCompileShader = reinterpret_cast <PFNGLCOMPILESHADERPROC>(wglGetProcAddress("glCompileShader"));
			OpenGLExt::glCreateProgram = reinterpret_cast <PFNGLCREATEPROGRAMPROC>(wglGetProcAddress("glCreateProgram"));
			OpenGLExt::glDeleteProgram = reinterpret_cast <PFNGLDELETEPROGRAMPROC>(wglGetProcAddress("glDeleteProgram"));
			OpenGLExt::glAttachShader = reinterpret_cast <PFNGLATTACHSHADERPROC>(wglGetProcAddress("glAttachShader"));
			OpenGLExt::glDetachShader = reinterpret_cast <PFNGLDETACHSHADERPROC>(wglGetProcAddress("glDetachShader"));
			OpenGLExt::glLinkProgram = reinterpret_cast <PFNGLLINKPROGRAMPROC>(wglGetProcAddress("glLinkProgram"));
			OpenGLExt::glUseProgram = reinterpret_cast <PFNGLUSEPROGRAMPROC>(wglGetProcAddress("glUseProgram"));
			OpenGLExt::glValidateProgram = reinterpret_cast <PFNGLVALIDATEPROGRAMPROC>(wglGetProcAddress("glValidateProgram"));
			OpenGLExt::glGetInfoLogARB = reinterpret_cast <PFNGLGETINFOLOGARBPROC>(wglGetProcAddress("glGetInfoLogARB"));
			OpenGLExt::glActiveTexture = reinterpret_cast <PFNGLACTIVETEXTUREPROC>(wglGetProcAddress("glActiveTexture"));
			OpenGLExt::glGetUniformLocation = reinterpret_cast <PFNGLGETUNIFORMLOCATIONPROC>(wglGetProcAddress("glGetUniformLocation"));
			OpenGLExt::glUniform1i = reinterpret_cast <PFNGLUNIFORM1IPROC>(wglGetProcAddress("glUniform1i"));
			OpenGLExt::glUniform1f = reinterpret_cast <PFNGLUNIFORM1FPROC>(wglGetProcAddress("glUniform1f"));
			OpenGLExt::glGenFramebuffers = reinterpret_cast <PFNGLGENFRAMEBUFFERSPROC>(wglGetProcAddress("glGenFramebuffers"));
			OpenGLExt::glGenRenderbuffers = reinterpret_cast <PFNGLGENRENDERBUFFERSPROC>(wglGetProcAddress("glGenRenderbuffers"));
			OpenGLExt::glBindRenderbuffer = reinterpret_cast <PFNGLBINDRENDERBUFFERPROC>(wglGetProcAddress("glBindRenderbuffer"));
			OpenGLExt::glRenderbufferStorage = reinterpret_cast <PFNGLRENDERBUFFERSTORAGEPROC>(wglGetProcAddress("glRenderbufferStorage"));
			OpenGLExt::glBindFramebuffer = reinterpret_cast <PFNGLBINDFRAMEBUFFERPROC>(wglGetProcAddress("glBindFramebuffer"));
			OpenGLExt::glFramebufferTexture2D = reinterpret_cast <PFNGLFRAMEBUFFERTEXTURE2DPROC>(wglGetProcAddress("glFramebufferTexture2D"));
			OpenGLExt::glDeleteFramebuffers = reinterpret_cast <PFNGLDELETEFRAMEBUFFERSPROC>(wglGetProcAddress("glDeleteFramebuffers"));
			OpenGLExt::glDeleteRenderbuffers = reinterpret_cast <PFNGLDELETERENDERBUFFERSPROC>(wglGetProcAddress("glDeleteRenderbuffers"));
			OpenGLExt::glDrawBuffers = reinterpret_cast <PFNGLDRAWBUFFERSPROC>(wglGetProcAddress("glDrawBuffers"));
			OpenGLExt::glCheckFramebufferStatus = reinterpret_cast <PFNGLCHECKFRAMEBUFFERSTATUSPROC>(wglGetProcAddress("glCheckFramebufferStatus"));
			OpenGLExt::glBindAttribLocation = reinterpret_cast <PFNGLBINDATTRIBLOCATIONPROC>(wglGetProcAddress("glBindAttribLocation"));
			OpenGLExt::glVertexAttrib2fv = reinterpret_cast <PFNGLVERTEXATTRIB2FVPROC>(wglGetProcAddress("glVertexAttrib2fv"));
			OpenGLExt::glVertexAttrib3fv = reinterpret_cast <PFNGLVERTEXATTRIB3FVPROC>(wglGetProcAddress("glVertexAttrib3fv"));
			OpenGLExt::glUniform3fv = reinterpret_cast <PFNGLUNIFORM3FVPROC>(wglGetProcAddress("glUniform3fv"));
			OpenGLExt::glUniform4fv = reinterpret_cast <PFNGLUNIFORM4FVPROC>(wglGetProcAddress("glUniform4fv"));
			OpenGLExt::glUniformMatrix4fv = reinterpret_cast <PFNGLUNIFORMMATRIX4FVPROC>(wglGetProcAddress("glUniformMatrix4fv"));
			OpenGLExt::glEnableVertexAttribArray = reinterpret_cast <PFNGLENABLEVERTEXATTRIBARRAYPROC>(wglGetProcAddress("glEnableVertexAttribArray"));
			OpenGLExt::glDisableVertexAttribArray = reinterpret_cast <PFNGLDISABLEVERTEXATTRIBARRAYPROC>(wglGetProcAddress("glDisableVertexAttribArray"));
			OpenGLExt::glDrawElementsInstanced = reinterpret_cast <PFNGLDRAWELEMENTSINSTANCEDPROC>(wglGetProcAddress("glDrawElementsInstanced"));
			OpenGLExt::glVertexAttribDivisor = reinterpret_cast <PFNGLVERTEXATTRIBDIVISORPROC>(wglGetProcAddress("glVertexAttribDivisor"));
			OpenGLExt::glVertexAttribPointer = reinterpret_cast <PFNGLVERTEXATTRIBPOINTERPROC>(wglGetProcAddress("glVertexAttribPointer"));
			OpenGLExt::glUniform2fv = reinterpret_cast <PFNGLUNIFORM2FVPROC>(wglGetProcAddress("glUniform2fv"));
			OpenGLExt::glUniformMatrix2fv = reinterpret_cast <PFNGLUNIFORMMATRIX2FVPROC>(wglGetProcAddress("glUniformMatrix2fv"));
			OpenGLExt::glUniformMatrix3fv = reinterpret_cast <PFNGLUNIFORMMATRIX3FVPROC>(wglGetProcAddress("glUniformMatrix3fv"));
			OpenGLExt::glUniform1ui = reinterpret_cast <PFNGLUNIFORM1UIPROC>(wglGetProcAddress("glUniform1ui"));
			OpenGLExt::glUniform1fv = reinterpret_cast <PFNGLUNIFORM1FVPROC>(wglGetProcAddress("glUniform1fv"));
			OpenGLExt::glUniform1iv = reinterpret_cast <PFNGLUNIFORM1IVPROC>(wglGetProcAddress("glUniform1iv"));
			OpenGLExt::glGenVertexArrays = reinterpret_cast <PFNGLGENVERTEXARRAYSPROC>(wglGetProcAddress("glGenVertexArrays"));
			OpenGLExt::glDeleteVertexArrays = reinterpret_cast <PFNGLDELETEVERTEXARRAYSPROC>(wglGetProcAddress("glDeleteVertexArrays"));
			OpenGLExt::glBindVertexArray = reinterpret_cast <PFNGLBINDVERTEXARRAYPROC>(wglGetProcAddress("glBindVertexArray"));
			OpenGLExt::glGenerateMipmap = reinterpret_cast <PFNGLGENERATEMIPMAPPROC>(wglGetProcAddress("glGenerateMipmap"));
			OpenGLExt::glGetShaderInfoLog = reinterpret_cast <PFNGLGETSHADERINFOLOGPROC>(wglGetProcAddress("glGetShaderInfoLog"));
		}
	}
}

#endif