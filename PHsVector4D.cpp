
/*
	2016.01.31
	Created by PHJ.
*/

#ifndef _PHS_VECTOR_4D_CPP

#define _PHS_VECTOR_4D_CPP

#include "PHsVector4D.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsTransformation
	{
		using namespace std;

		Vector4D::Vector4D(Vector4D &&sNewVector4D)
		{
			copy(sNewVector4D.vElement, sNewVector4D.vElement + 4u, this->vElement);
		}

		Vector4D::Vector4D(const Vector4D &sNewVector4D)
		{
			copy(sNewVector4D.vElement, sNewVector4D.vElement + 4u, this->vElement);
		}

		Vector4D::Vector4D(array <Float, 4u> &&sNewVector4D)
		{
			copy(sNewVector4D.begin(), sNewVector4D.end(), this->vElement);
		}

		Vector4D::Vector4D(const array <Float, 4u> &sNewVector4D)
		{
			copy(sNewVector4D.begin(), sNewVector4D.end(), this->vElement);
		}

		Vector4D &Vector4D::operator=(Vector4D &&sNewVector4D)
		{
			copy(sNewVector4D.vElement, sNewVector4D.vElement + 4u, this->vElement);

			return *this;
		}

		Vector4D &Vector4D::operator=(const Vector4D &sNewVector4D)
		{
			copy(sNewVector4D.vElement, sNewVector4D.vElement + 4u, this->vElement);

			return *this;
		}

		Vector4D &Vector4D::operator=(array <Float, 4u> &&sNewVector4D)
		{
			copy(sNewVector4D.begin(), sNewVector4D.end(), this->vElement);

			return *this;
		}

		Vector4D &Vector4D::operator=(const array <Float, 4u> &sNewVector4D)
		{
			copy(sNewVector4D.begin(), sNewVector4D.end(), this->vElement);

			return *this;
		}

		Void Vector4D::normalizeVector()
		{
			Float nLength = 1.0f / this->vectorLength();

			if(!isinf(nLength))
			{
				for(Float &nElement : this->vElement)
					nElement *= nLength;
			}
		}

		Void Vector4D::zeroVector(Float nNewW)
		{
			fill(this->vElement, this->vElement + 3u, 0.0f);
			this->vElement[3] = nNewW;
		}

		Void Vector4D::multiplyVector(Float nNewFactor)
		{
			for(Float &nElement : this->vElement)
				nElement *= nNewFactor;
		}

		Void Vector4D::multiplyMatrix(const Float *pNewMatrix)
		{
			Float4Ext sRow = _mm_load_ps(this->vElement);

			Float4Ext sCol1 = _mm_load_ps(pNewMatrix);
			Float4Ext sCol2 = _mm_load_ps(pNewMatrix + 4);
			Float4Ext sCol3 = _mm_load_ps(pNewMatrix + 8);
			Float4Ext sCol4 = _mm_load_ps(pNewMatrix + 12);

			_MM_TRANSPOSE4_PS(sCol1, sCol2, sCol3, sCol4);

			this->vElement[0] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow, sCol1), sRow), sRow).m128_f32[0];
			this->vElement[1] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow, sCol2), sRow), sRow).m128_f32[0];
			this->vElement[2] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow, sCol3), sRow), sRow).m128_f32[0];
			this->vElement[3] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow, sCol4), sRow), sRow).m128_f32[0];
		}

		Float Vector4D::vectorLength() const
		{
			return sqrt(
				pow(this->vElement[0], 2.0f) +
				pow(this->vElement[1], 2.0f) +
				pow(this->vElement[2], 2.0f));
		}
	}
}

#endif