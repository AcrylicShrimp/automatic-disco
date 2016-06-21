
/*
	2016.01.31
	Created by PHJ.
*/

#ifndef _PHS_VECTOR_4D_H

#define _PHS_VECTOR_4D_H

#include "PHsCommon.h"

#include <algorithm>
#include <array>
#include <cmath>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsTransformation
	{
		class alignas(16) Vector4D
		{
		private:
			Float vElement[4];

		public:
			Vector4D() = default;
			Vector4D(Vector4D &&sNewVector4D);
			Vector4D(const Vector4D &sNewVector4D);
			Vector4D(std::array <Float, 4u> &&sNewVector4D);
			Vector4D(const std::array <Float, 4u> &sNewVector4D);
			~Vector4D() = default;

		public:
			inline operator Float *();
			inline operator const Float *() const;

		public:
			Vector4D &operator=(Vector4D &&sNewVector4D);
			Vector4D &operator=(const Vector4D &sNewVector4D);
			Vector4D &operator=(std::array <Float, 4u> &&sNewVector4D);
			Vector4D &operator=(const std::array <Float, 4u> &sNewVector4D);

			Void normalizeVector();
			Void zeroVector(Float nNewW = 0.0f);
			Void multiplyVector(Float nNewFactor);
			Void multiplyMatrix(const Float *pNewMatrix);
			Float vectorLength() const;
		};

		inline Vector4D::operator Float *()
		{
			return this->vElement;
		}

		inline Vector4D::operator const Float *() const
		{
			return this->vElement;
		}
	}
}

#endif