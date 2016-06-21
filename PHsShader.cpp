
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_SHADER_CPP

#define _PHS_SHADER_CPP

#include "PHsShader.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		using namespace std;

		const Shader *Shader::pShader{nullptr};

		Shader::Shader(Shader &&sNewShader)
		{
			this->nProgram = sNewShader.nProgram, sNewShader.nProgram = 0u;
			this->nVertexShader = sNewShader.nVertexShader, sNewShader.nVertexShader = 0u;
			this->nGeometryShader = sNewShader.nGeometryShader, sNewShader.nGeometryShader = 0u;
			this->nFragmentShader = sNewShader.nFragmentShader, sNewShader.nFragmentShader = 0u;

			if(Shader::pShader == &sNewShader)
				Shader::pShader = this;
		}

		Shader::~Shader()
		{
			this->finalizeShader();
		}

		Shader &Shader::operator=(Shader &&sNewShader)
		{
			this->deleteShader();

			if(this->nProgram)
				OpenGLExt::glDeleteProgram(this->nProgram);

			this->nProgram = sNewShader.nProgram, sNewShader.nProgram = 0u;
			this->nVertexShader = sNewShader.nVertexShader, sNewShader.nVertexShader = 0u;
			this->nGeometryShader = sNewShader.nGeometryShader, sNewShader.nGeometryShader = 0u;
			this->nFragmentShader = sNewShader.nFragmentShader, sNewShader.nFragmentShader = 0u;

			if(Shader::pShader == &sNewShader)
				Shader::pShader = this;

			return *this;
		}

		Void Shader::initializeShader()
		{
			this->nProgram = OpenGLExt::glCreateProgram();
		}

		Void Shader::finalizeShader()
		{
			this->deleteShader();

			if(this->nProgram)
				OpenGLExt::glDeleteProgram(this->nProgram), this->nProgram = 0u;

			if(Shader::pShader == this)
				Shader::pShader = nullptr;
		}

		Void Shader::createShader(const wstring &sNewVertexShaderPath, const wstring &sNewGeometryShaderPath, const wstring &sNewFragmentShaderPath)
		{
			this->nVertexShader = OpenGLExt::glCreateShader(GL_VERTEX_SHADER);
			this->nFragmentShader = OpenGLExt::glCreateShader(GL_FRAGMENT_SHADER);

			if(sNewGeometryShaderPath.empty())
			{
				UTF8Reader sVertexReader{sNewVertexShaderPath};
				UTF8Reader sFragmentReader{sNewFragmentShaderPath};

				const Char *pVertexShaderSourcePointer = sVertexReader.readerContent().c_str();
				const Char *pFragmentShaderSourcePointer = sFragmentReader.readerContent().c_str();

				OpenGLExt::glShaderSource(this->nVertexShader, 1u, &pVertexShaderSourcePointer, nullptr);
				OpenGLExt::glShaderSource(this->nFragmentShader, 1u, &pFragmentShaderSourcePointer, nullptr);

				OpenGLExt::glCompileShader(this->nVertexShader);
				OpenGLExt::glCompileShader(this->nFragmentShader);

#ifdef _DEBUG
				Char vVertexShaderLog[4096]
				{
					//Empty.
				};
				Char vFragmentShaderLog[4096]
				{
					//Empty.
				};

				Int nVertexShaderLogLength;
				Int nFragmentShaderLogLength;

				OpenGLExt::glGetShaderInfoLog(this->nVertexShader, 4096u, &nVertexShaderLogLength, vVertexShaderLog);
				OpenGLExt::glGetShaderInfoLog(this->nFragmentShader, 4096u, &nFragmentShaderLogLength, vFragmentShaderLog);

				if(nVertexShaderLogLength > 1u)
				{
					wChar vVertexShaderCompilationMessage[5120]
					{

					};

					wsprintf(vVertexShaderCompilationMessage, L"Vertex shader compilation message :\n\n%S\n\nSource file : %s", vVertexShaderLog, sNewVertexShaderPath.c_str());
					MessageBox(nullptr, vVertexShaderCompilationMessage, L"Vertex shader compilation", MB_OK | MB_ICONEXCLAMATION);
				}

				if(nFragmentShaderLogLength > 1u)
				{
					wChar vFragmentShaderCompilationMessage[5120]
					{

					};

					wsprintf(vFragmentShaderCompilationMessage, L"Fragment shader compilation message :\n\n%S\n\nSource file : %s", vFragmentShaderLog, sNewFragmentShaderPath.c_str());
					MessageBox(nullptr, vFragmentShaderCompilationMessage, L"Fragment shader compilation", MB_OK | MB_ICONEXCLAMATION);
				}
#endif
				OpenGLExt::glAttachShader(this->nProgram, this->nVertexShader);
				OpenGLExt::glAttachShader(this->nProgram, this->nFragmentShader);

				OpenGLExt::glLinkProgram(this->nProgram);
			}
			else
			{
				this->nGeometryShader = OpenGLExt::glCreateShader(GL_GEOMETRY_SHADER);

				UTF8Reader sVertexReader{sNewVertexShaderPath};
				UTF8Reader sGeometryReader{sNewGeometryShaderPath};
				UTF8Reader sFragmentReader{sNewFragmentShaderPath};

				const Char *pVertexShaderSourcePointer = sVertexReader.readerContent().c_str();
				const Char *pGeometryShaderSourcePointer = sGeometryReader.readerContent().c_str();
				const Char *pFragmentShaderSourcePointer = sFragmentReader.readerContent().c_str();

				OpenGLExt::glShaderSource(this->nVertexShader, 1u, &pVertexShaderSourcePointer, nullptr);
				OpenGLExt::glShaderSource(this->nGeometryShader, 1u, &pGeometryShaderSourcePointer, nullptr);
				OpenGLExt::glShaderSource(this->nFragmentShader, 1u, &pFragmentShaderSourcePointer, nullptr);

				OpenGLExt::glCompileShader(this->nVertexShader);
				OpenGLExt::glCompileShader(this->nGeometryShader);
				OpenGLExt::glCompileShader(this->nFragmentShader);

#ifdef _DEBUG
				Char vVertexShaderLog[4096]
				{
					//Empty.
				};
				Char vGeometryShaderLog[4096]
				{
					//Empty.
				};
				Char vFragmentShaderLog[4096]
				{
					//Empty.
				};

				Int nVertexShaderLogLength;
				Int nGeometryShaderLogLength;
				Int nFragmentShaderLogLength;

				OpenGLExt::glGetShaderInfoLog(this->nVertexShader, 4096u, &nVertexShaderLogLength, vVertexShaderLog);
				OpenGLExt::glGetShaderInfoLog(this->nGeometryShader, 4096u, &nGeometryShaderLogLength, vGeometryShaderLog);
				OpenGLExt::glGetShaderInfoLog(this->nFragmentShader, 4096u, &nFragmentShaderLogLength, vFragmentShaderLog);

				if(nVertexShaderLogLength > 1u)
				{
					wChar vVertexShaderCompilationMessage[5120]
					{

					};

					wsprintf(vVertexShaderCompilationMessage, L"Vertex shader compilation message :\n\n%S\n\nSource file : %s", vVertexShaderLog, sNewVertexShaderPath.c_str());
					MessageBox(nullptr, vVertexShaderCompilationMessage, L"Vertex shader compilation", MB_OK | MB_ICONEXCLAMATION);
				}

				if(nGeometryShaderLogLength > 1u)
				{
					wChar vGeometryShaderCompilationMessage[5120]
					{

					};

					wsprintf(vGeometryShaderCompilationMessage, L"Geometry shader compilation message :\n\n%S\n\nSource file : %s", vGeometryShaderLog, sNewGeometryShaderPath.c_str());
					MessageBox(nullptr, vGeometryShaderCompilationMessage, L"Geometry shader compilation", MB_OK | MB_ICONEXCLAMATION);
				}

				if(nFragmentShaderLogLength > 1u)
				{
					wChar vFragmentShaderCompilationMessage[5120]
					{

					};

					wsprintf(vFragmentShaderCompilationMessage, L"Fragment shader compilation message :\n\n%S\n\nSource file : %s", vFragmentShaderLog, sNewFragmentShaderPath.c_str());
					MessageBox(nullptr, vFragmentShaderCompilationMessage, L"Fragment shader compilation", MB_OK | MB_ICONEXCLAMATION);
				}
#endif
				OpenGLExt::glAttachShader(this->nProgram, this->nVertexShader);
				OpenGLExt::glAttachShader(this->nProgram, this->nGeometryShader);
				OpenGLExt::glAttachShader(this->nProgram, this->nFragmentShader);

				OpenGLExt::glLinkProgram(this->nProgram);
			}
		}

		Void Shader::deleteShader()
		{
			if(!this->nVertexShader)
				return;

			OpenGLExt::glDetachShader(this->nProgram, this->nVertexShader);
			OpenGLExt::glDeleteShader(this->nVertexShader), this->nVertexShader = 0u;

			OpenGLExt::glDetachShader(this->nProgram, this->nFragmentShader);
			OpenGLExt::glDeleteShader(this->nFragmentShader), this->nFragmentShader = 0u;

			if(!this->nGeometryShader)
				return;

			OpenGLExt::glDetachShader(this->nProgram, this->nGeometryShader);
			OpenGLExt::glDeleteShader(this->nGeometryShader), this->nGeometryShader = 0u;
		}
	}
}

#endif