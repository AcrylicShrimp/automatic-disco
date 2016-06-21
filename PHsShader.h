
/*
	2016.01.27
	Created by PHJ.
*/

#ifndef _PHS_SHADER_H

#define _PHS_SHADER_H

#include "PHsCommon.h"
#include "PHsOpenGLExt.h"
#include "PHsUTF8Reader.h"
#include "PHsVideoBufferSlot.h"

#include <string>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsRender
	{
		class Shader final
		{
		private:
			static const Shader *pShader;

		private:
			uInt nProgram{0u};
			uInt nVertexShader{0u};
			uInt nGeometryShader{0u};
			uInt nFragmentShader{0u};

		public:
			Shader() = default;
			Shader(Shader &&sNewShader);
			Shader(const Shader &sNewShader) = delete;
			~Shader();

		public:
			inline operator uInt() const;

		public:
			Shader &operator=(Shader &&sNewShader);
			Shader &operator=(const Shader &sNewShader) = delete;

			Void initializeShader();
			Void finalizeShader();
			Void createShader(const std::wstring &sNewVertexShaderPath, const std::wstring &sNewGeometryShaderPath, const std::wstring &sNewFragmentShaderPath);
			Void deleteShader();

		public:
			inline static Void activeShader(const Shader &sNewShader);
			inline static Void setUniformFloat1(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData);
			inline static Void setUniformFloat2(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData);
			inline static Void setUniformFloat3(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData);
			inline static Void setUniformFloat4(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData);
			inline static Void setUniformMatrix22(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData, Bool bNewUniformTransposed = false);
			inline static Void setUniformMatrix33(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData, Bool bNewUniformTransposed = false);
			inline static Void setUniformMatrix44(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData, Bool bNewUniformTransposed = false);
			inline static Void setUniformSampler(const std::string &sNewUniformName, uInt nNewUniformNum, const Int *pNewUniformData);
		};

		inline Shader::operator uInt() const
		{
			return this->nProgram;
		}

		inline Void Shader::activeShader(const Shader &sNewShader)
		{
			OpenGLExt::glUseProgram(sNewShader);

			Shader::pShader = &sNewShader;
		}

		inline Void Shader::setUniformFloat1(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData)
		{
			OpenGLExt::glUniform1fv(OpenGLExt::glGetUniformLocation(*Shader::pShader, sNewUniformName.c_str()), nNewUniformNum, pNewUniformData);
		}

		inline Void Shader::setUniformFloat2(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData)
		{
			OpenGLExt::glUniform2fv(OpenGLExt::glGetUniformLocation(*Shader::pShader, sNewUniformName.c_str()), nNewUniformNum, pNewUniformData);
		}

		inline Void Shader::setUniformFloat3(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData)
		{
			OpenGLExt::glUniform3fv(OpenGLExt::glGetUniformLocation(*Shader::pShader, sNewUniformName.c_str()), nNewUniformNum, pNewUniformData);
		}

		inline Void Shader::setUniformFloat4(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData)
		{
			OpenGLExt::glUniform4fv(OpenGLExt::glGetUniformLocation(*Shader::pShader, sNewUniformName.c_str()), nNewUniformNum, pNewUniformData);
		}

		inline Void Shader::setUniformMatrix22(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData, Bool bNewUniformTransposed)
		{
			OpenGLExt::glUniformMatrix2fv(OpenGLExt::glGetUniformLocation(*Shader::pShader, sNewUniformName.c_str()), nNewUniformNum, bNewUniformTransposed, pNewUniformData);
		}

		inline Void Shader::setUniformMatrix33(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData, Bool bNewUniformTransposed)
		{
			OpenGLExt::glUniformMatrix3fv(OpenGLExt::glGetUniformLocation(*Shader::pShader, sNewUniformName.c_str()), nNewUniformNum, bNewUniformTransposed, pNewUniformData);
		}

		inline Void Shader::setUniformMatrix44(const std::string &sNewUniformName, uInt nNewUniformNum, const Float *pNewUniformData, Bool bNewUniformTransposed)
		{
			OpenGLExt::glUniformMatrix4fv(OpenGLExt::glGetUniformLocation(*Shader::pShader, sNewUniformName.c_str()), nNewUniformNum, bNewUniformTransposed, pNewUniformData);
		}

		inline Void Shader::setUniformSampler(const std::string &sNewUniformName, uInt nNewUniformNum, const Int *pNewUniformData)
		{
			OpenGLExt::glUniform1iv(OpenGLExt::glGetUniformLocation(*Shader::pShader, sNewUniformName.c_str()), nNewUniformNum, pNewUniformData);
		}
	}
}

#endif