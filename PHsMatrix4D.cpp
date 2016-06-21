
/*
	2016.01.30
	Created by PHJ.
*/

#ifndef _PHS_MATRIX_4D_CPP

#define _PHS_MATRIX_4D_CPP

#include "PHsMatrix4D.h"

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsTransformation
	{
		using namespace std;

		Matrix4D::Matrix4D(Matrix4D &&sNewMatrix4D)
		{
			copy(sNewMatrix4D.vElement, sNewMatrix4D.vElement + 16u, this->vElement);
		}

		Matrix4D::Matrix4D(const Matrix4D &sNewMatrix4D)
		{
			copy(sNewMatrix4D.vElement, sNewMatrix4D.vElement + 16u, this->vElement);
		}

		Matrix4D::Matrix4D(array <Float, 4u> &&sNewMatrix4D)
		{
			copy(sNewMatrix4D.begin(), sNewMatrix4D.end(), this->vElement);
		}

		Matrix4D::Matrix4D(const array <Float, 4u> &sNewMatrix4D)
		{
			copy(sNewMatrix4D.begin(), sNewMatrix4D.end(), this->vElement);
		}

		Matrix4D &Matrix4D::operator=(Matrix4D &&sNewMatrix4D)
		{
			copy(sNewMatrix4D.vElement, sNewMatrix4D.vElement + 16u, this->vElement);

			return *this;
		}

		Matrix4D &Matrix4D::operator=(const Matrix4D &sNewMatrix4D)
		{
			copy(sNewMatrix4D.vElement, sNewMatrix4D.vElement + 16u, this->vElement);

			return *this;
		}

		Matrix4D &Matrix4D::operator=(std::array <Float, 4u> &&sNewMatrix4D)
		{
			copy(sNewMatrix4D.begin(), sNewMatrix4D.end(), this->vElement);

			return *this;
		}

		Matrix4D &Matrix4D::operator=(const std::array <Float, 4u> &sNewMatrix4D)
		{
			copy(sNewMatrix4D.begin(), sNewMatrix4D.end(), this->vElement);

			return *this;
		}

		Void Matrix4D::zeroMatrix()
		{
			fill(this->vElement, this->vElement + 16u, 0.0f);
		}

		Void Matrix4D::identityMatrix()
		{
			fill(this->vElement, this->vElement + 16u, 0.0f);

			this->vElement[0] =
				this->vElement[5] =
				this->vElement[10] =
				this->vElement[15] = 1.0f;
		}

		Void Matrix4D::transposeMatrix()
		{
			Float4Ext sRow1 = _mm_load_ps(this->vElement);
			Float4Ext sRow2 = _mm_load_ps(this->vElement + 4);
			Float4Ext sRow3 = _mm_load_ps(this->vElement + 8);
			Float4Ext sRow4 = _mm_load_ps(this->vElement + 12);

			_MM_TRANSPOSE4_PS(sRow1, sRow2, sRow3, sRow4);

			_mm_store_ps(this->vElement, sRow1);
			_mm_store_ps(this->vElement + 4, sRow2);
			_mm_store_ps(this->vElement + 8, sRow3);
			_mm_store_ps(this->vElement + 12, sRow4);
		}

		Bool Matrix4D::inverseMatrix()
		{
			Matrix4D sTemporary;

			sTemporary[0] =
				this->vElement[5] * this->vElement[10] * this->vElement[15] - this->vElement[5] * this->vElement[11] * this->vElement[14] -
				this->vElement[9] * this->vElement[6] * this->vElement[15] + this->vElement[9] * this->vElement[7] * this->vElement[14] +
				this->vElement[13] * this->vElement[6] * this->vElement[11] - this->vElement[13] * this->vElement[7] * this->vElement[10];

			sTemporary[4] =
				-this->vElement[4] * this->vElement[10] * this->vElement[15] + this->vElement[4] * this->vElement[11] * this->vElement[14] +
				this->vElement[8] * this->vElement[6] * this->vElement[15] - this->vElement[8] * this->vElement[7] * this->vElement[14] -
				this->vElement[12] * this->vElement[6] * this->vElement[11] + this->vElement[12] * this->vElement[7] * this->vElement[10];

			sTemporary[8] =
				this->vElement[4] * this->vElement[9] * this->vElement[15] - this->vElement[4] * this->vElement[11] * this->vElement[13] -
				this->vElement[8] * this->vElement[5] * this->vElement[15] + this->vElement[8] * this->vElement[7] * this->vElement[13] +
				this->vElement[12] * this->vElement[5] * this->vElement[11] - this->vElement[12] * this->vElement[7] * this->vElement[9];

			sTemporary[12] =
				-this->vElement[4] * this->vElement[9] * this->vElement[14] + this->vElement[4] * this->vElement[10] * this->vElement[13] +
				this->vElement[8] * this->vElement[5] * this->vElement[14] - this->vElement[8] * this->vElement[6] * this->vElement[13] -
				this->vElement[12] * this->vElement[5] * this->vElement[10] + this->vElement[12] * this->vElement[6] * this->vElement[9];

			Float nFactor = this->vElement[0] * sTemporary[0] + this->vElement[1] * sTemporary[4] + this->vElement[2] * sTemporary[8] + this->vElement[3] * sTemporary[12];

			if(nFactor == 0.0f)
				return false;
			
			nFactor = 1.0f / nFactor;

			sTemporary[1] =
				-this->vElement[1] * this->vElement[10] * this->vElement[15] + this->vElement[1] * this->vElement[11] * this->vElement[14] +
				this->vElement[9] * this->vElement[2] * this->vElement[15] - this->vElement[9] * this->vElement[3] * this->vElement[14] -
				this->vElement[13] * this->vElement[2] * this->vElement[11] + this->vElement[13] * this->vElement[3] * this->vElement[10];

			sTemporary[5] =
				this->vElement[0] * this->vElement[10] * this->vElement[15] - this->vElement[0] * this->vElement[11] * this->vElement[14] -
				this->vElement[8] * this->vElement[2] * this->vElement[15] + this->vElement[8] * this->vElement[3] * this->vElement[14] +
				this->vElement[12] * this->vElement[2] * this->vElement[11] - this->vElement[12] * this->vElement[3] * this->vElement[10];

			sTemporary[9] =
				-this->vElement[0] * this->vElement[9] * this->vElement[15] + this->vElement[0] * this->vElement[11] * this->vElement[13] +
				this->vElement[8] * this->vElement[1] * this->vElement[15] - this->vElement[8] * this->vElement[3] * this->vElement[13] -
				this->vElement[12] * this->vElement[1] * this->vElement[11] + this->vElement[12] * this->vElement[3] * this->vElement[9];

			sTemporary[13] =
				this->vElement[0] * this->vElement[9] * this->vElement[14] - this->vElement[0] * this->vElement[10] * this->vElement[13] -
				this->vElement[8] * this->vElement[1] * this->vElement[14] + this->vElement[8] * this->vElement[2] * this->vElement[13] +
				this->vElement[12] * this->vElement[1] * this->vElement[10] - this->vElement[12] * this->vElement[2] * this->vElement[9];

			sTemporary[2] =
				this->vElement[1] * this->vElement[6] * this->vElement[15] - this->vElement[1] * this->vElement[7] * this->vElement[14] -
				this->vElement[5] * this->vElement[2] * this->vElement[15] + this->vElement[5] * this->vElement[3] * this->vElement[14] +
				this->vElement[13] * this->vElement[2] * this->vElement[7] - this->vElement[13] * this->vElement[3] * this->vElement[6];

			sTemporary[6] =
				-this->vElement[0] * this->vElement[6] * this->vElement[15] + this->vElement[0] * this->vElement[7] * this->vElement[14] +
				this->vElement[4] * this->vElement[2] * this->vElement[15] - this->vElement[4] * this->vElement[3] * this->vElement[14] -
				this->vElement[12] * this->vElement[2] * this->vElement[7] + this->vElement[12] * this->vElement[3] * this->vElement[6];

			sTemporary[10] =
				this->vElement[0] * this->vElement[5] * this->vElement[15] - this->vElement[0] * this->vElement[7] * this->vElement[13] -
				this->vElement[4] * this->vElement[1] * this->vElement[15] + this->vElement[4] * this->vElement[3] * this->vElement[15] +
				this->vElement[12] * this->vElement[1] * this->vElement[7] - this->vElement[12] * this->vElement[3] * this->vElement[5];

			sTemporary[14] =
				-this->vElement[0] * this->vElement[5] * this->vElement[14] + this->vElement[0] * this->vElement[6] * this->vElement[13] +
				this->vElement[4] * this->vElement[1] * this->vElement[14] - this->vElement[4] * this->vElement[2] * this->vElement[13] -
				this->vElement[12] * this->vElement[1] * this->vElement[6] + this->vElement[12] * this->vElement[2] * this->vElement[5];

			sTemporary[3] =
				-this->vElement[1] * this->vElement[6] * this->vElement[11] + this->vElement[1] * this->vElement[7] * this->vElement[10] +
				this->vElement[5] * this->vElement[2] * this->vElement[11] - this->vElement[5] * this->vElement[3] * this->vElement[10] -
				this->vElement[9] * this->vElement[2] * this->vElement[7] + this->vElement[9] * this->vElement[3] * this->vElement[6];

			sTemporary[7] =
				this->vElement[0] * this->vElement[6] * this->vElement[11] - this->vElement[0] * this->vElement[7] * this->vElement[10] -
				this->vElement[4] * this->vElement[2] * this->vElement[11] + this->vElement[4] * this->vElement[3] * this->vElement[10] +
				this->vElement[8] * this->vElement[2] * this->vElement[7] - this->vElement[8] * this->vElement[3] * this->vElement[6];

			sTemporary[11] =
				-this->vElement[0] * this->vElement[5] * this->vElement[11] + this->vElement[0] * this->vElement[7] * this->vElement[9] +
				this->vElement[4] * this->vElement[1] * this->vElement[11] - this->vElement[4] * this->vElement[3] * this->vElement[9] -
				this->vElement[8] * this->vElement[1] * this->vElement[7] + this->vElement[8] * this->vElement[3] * this->vElement[5];

			sTemporary[15] =
				this->vElement[0] * this->vElement[5] * this->vElement[10] - this->vElement[0] * this->vElement[6] * this->vElement[9] -
				this->vElement[4] * this->vElement[1] * this->vElement[10] + this->vElement[4] * this->vElement[2] * this->vElement[9] +
				this->vElement[8] * this->vElement[1] * this->vElement[6] - this->vElement[8] * this->vElement[2] * this->vElement[5];

			for(uInt nIndex = 0u ; nIndex < 16u ; ++nIndex)
				this->vElement[nIndex] = sTemporary[nIndex] * nFactor;

			return true;
		}

		Void Matrix4D::scaleMatrix(Float nNewFactor)
		{
			fill(this->vElement, this->vElement + 16u, 0.0f);

			this->vElement[0] =
				this->vElement[5] =
				this->vElement[10] = nNewFactor;
			
			this->vElement[15] = 1.0f;
		}

		Void Matrix4D::scaleMatrix(Float nNewFactorX, Float nNewFactorY, Float nNewFactorZ)
		{
			fill(this->vElement, this->vElement + 16u, 0.0f);

			this->vElement[0] = nNewFactorX;
			this->vElement[5] = nNewFactorY;
			this->vElement[10] = nNewFactorZ;
			this->vElement[15] = 1.0f;
		}

		Void Matrix4D::rotateMatrix(Float nNewAngle, const Float *pNewAxis)
		{
			fill(this->vElement, this->vElement + 16u, 0.0f);

			const Float nSin = sin(nNewAngle);
			const Float nCos = cos(nNewAngle);
			const Float nOneCos = 1.0f - nCos;

			this->vElement[0] = nOneCos * pNewAxis[0] * pNewAxis[0] + nCos;
			this->vElement[1] = nOneCos * pNewAxis[0] * pNewAxis[1] + pNewAxis[2] * nSin;
			this->vElement[2] = nOneCos * pNewAxis[0] * pNewAxis[2] - pNewAxis[1] * nSin;

			this->vElement[4] = nOneCos * pNewAxis[0] * pNewAxis[1] - pNewAxis[2] * nSin;
			this->vElement[5] = nOneCos * pNewAxis[1] * pNewAxis[1] + nCos;
			this->vElement[6] = nOneCos * pNewAxis[1] * pNewAxis[2] + pNewAxis[0] * nSin;

			this->vElement[8] = nOneCos * pNewAxis[0] * pNewAxis[2] + pNewAxis[1] * nSin;
			this->vElement[9] = nOneCos * pNewAxis[1] * pNewAxis[2] - pNewAxis[0] * nSin;
			this->vElement[10] = nOneCos * pNewAxis[2] * pNewAxis[2] + nCos;

			this->vElement[15] = 1.0f;
		}

		Void Matrix4D::rotateMatrixX(Float nNewAngleX)
		{
			fill(this->vElement, this->vElement + 16u, 0.0f);

			this->vElement[5] =
				this->vElement[10] = cos(nNewAngleX);

			this->vElement[6] = sin(nNewAngleX);
			this->vElement[9] = -this->vElement[6];

			this->vElement[0] =
				this->vElement[15] = 1.0f;
		}

		Void Matrix4D::rotateMatrixY(Float nNewAngleY)
		{
			fill(this->vElement, this->vElement + 16u, 0.0f);

			this->vElement[0] =
				this->vElement[10] = cos(nNewAngleY);

			this->vElement[8] = sin(nNewAngleY);
			this->vElement[2] = -this->vElement[8];

			this->vElement[5] =
				this->vElement[15] = 1.0f;
		}

		Void Matrix4D::rotateMatrixZ(Float nNewAngleZ)
		{
			fill(this->vElement, this->vElement + 16u, 0.0f);

			this->vElement[0] =
				this->vElement[5] = cos(nNewAngleZ);

			this->vElement[1] = sin(nNewAngleZ);
			this->vElement[4] = -this->vElement[1];

			this->vElement[10] =
				this->vElement[15] = 1.0f;
		}

		Void Matrix4D::translateMatrix(Float nNewTranX, Float nNewTranY, Float nNewTranZ)
		{
			fill(this->vElement, this->vElement + 16u, 0.0f);

			this->vElement[0] =
				this->vElement[5] =
				this->vElement[10] =
				this->vElement[15] = 1.0f;

			this->vElement[12] = nNewTranX;
			this->vElement[13] = nNewTranY;
			this->vElement[14] = nNewTranZ;
		}

		Void Matrix4D::perspectiveMatrix(Float nNewAspect, Float nNewFieldOfView, Float nNewNear, Float nNewFar)
		{
			fill(this->vElement, this->vElement + 16u, 0.0f);

			Float nTangent = 1.0f / tan(nNewFieldOfView * 0.5f);
			Float nFarNear = 1.0f / (nNewNear - nNewFar);

			this->vElement[0] = nNewNear * nTangent / nNewAspect;
			this->vElement[5] = nTangent;
			this->vElement[10] = nNewFar * nFarNear;
			this->vElement[11] = -1.0f;
			this->vElement[14] = nNewNear * nNewFar * nFarNear;
		}

		Void Matrix4D::orthographicMatrix(Float nNewNear, Float nNewFar, Float nNewTop, Float nNewRight)
		{
			fill(this->vElement, this->vElement + 16u, 0.0f);

			const Float nNearFar = 1.0f / (nNewNear - nNewFar);

			this->vElement[0] = 1.0f / nNewRight;
			this->vElement[5] = 1.0f / nNewTop;
			this->vElement[10] = 2.0f * nNearFar;
			this->vElement[14] = (nNewNear + nNewFar) * nNearFar;
			this->vElement[15] = 1.0f;
		}

		Void Matrix4D::multiplyMatrix(Float nNewFactor)
		{
			for(Float &nElement : this->vElement)
				nElement *= nNewFactor;
		}

		Void Matrix4D::multiplyMatrix(const Float *pNewMatrix)
		{
			Float4Ext sCol1 = _mm_load_ps(pNewMatrix);
			Float4Ext sCol2 = _mm_load_ps(pNewMatrix + 4);
			Float4Ext sCol3 = _mm_load_ps(pNewMatrix + 8);
			Float4Ext sCol4 = _mm_load_ps(pNewMatrix + 12);

			Float4Ext sRow1 = _mm_shuffle_ps(sCol1, sCol2, 0x44);
			Float4Ext sRow2 = _mm_shuffle_ps(sCol1, sCol2, 0xEE);
			Float4Ext sRow3 = _mm_shuffle_ps(sCol3, sCol4, 0x44);
			Float4Ext sRow4 = _mm_shuffle_ps(sCol3, sCol4, 0xEE);

			sCol1 = _mm_shuffle_ps(sRow1, sRow3, 0x88);
			sCol2 = _mm_shuffle_ps(sRow1, sRow3, 0xDD);
			sCol3 = _mm_shuffle_ps(sRow2, sRow4, 0x88);
			sCol4 = _mm_shuffle_ps(sRow2, sRow4, 0xDD);

			sRow1 = _mm_load_ps(this->vElement);
			sRow2 = _mm_load_ps(this->vElement + 4);
			sRow3 = _mm_load_ps(this->vElement + 8);
			sRow4 = _mm_load_ps(this->vElement + 12);

			this->vElement[0] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow1, sCol1), sRow1), sRow1).m128_f32[0];
			this->vElement[1] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow1, sCol2), sRow1), sRow1).m128_f32[0];
			this->vElement[2] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow1, sCol3), sRow1), sRow1).m128_f32[0];
			this->vElement[3] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow1, sCol4), sRow1), sRow1).m128_f32[0];

			this->vElement[4] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow2, sCol1), sRow2), sRow2).m128_f32[0];
			this->vElement[5] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow2, sCol2), sRow2), sRow2).m128_f32[0];
			this->vElement[6] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow2, sCol3), sRow2), sRow2).m128_f32[0];
			this->vElement[7] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow2, sCol4), sRow2), sRow2).m128_f32[0];

			this->vElement[8] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow3, sCol1), sRow3), sRow3).m128_f32[0];
			this->vElement[9] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow3, sCol2), sRow3), sRow3).m128_f32[0];
			this->vElement[10] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow3, sCol3), sRow3), sRow3).m128_f32[0];
			this->vElement[11] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow3, sCol4), sRow3), sRow3).m128_f32[0];

			this->vElement[12] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow4, sCol1), sRow4), sRow4).m128_f32[0];
			this->vElement[13] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow4, sCol2), sRow4), sRow4).m128_f32[0];
			this->vElement[14] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow4, sCol3), sRow4), sRow4).m128_f32[0];
			this->vElement[15] = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(sRow4, sCol4), sRow4), sRow4).m128_f32[0];
		}
	}
}

#endif