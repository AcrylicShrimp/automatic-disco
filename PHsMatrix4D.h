
/*
	2016.01.30
	Created by PHJ.
*/

#ifndef _PHS_MATRIX_4D_H

#define _PHS_MATRIX_4D_H

#include "PHsCommon.h"

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <intrin.h>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsTransformation
	{
		class alignas(16) Matrix4D final
		{
		private:
			Float vElement[16];

		public:
			Matrix4D() = default;
			Matrix4D(Matrix4D &&sNewMatrix4D);
			Matrix4D(const Matrix4D &sNewMatrix4D);
			Matrix4D(std::array <Float, 4u> &&sNewMatrix4D);
			Matrix4D(const std::array <Float, 4u> &sNewMatrix4D);
			~Matrix4D() = default;

		public:
			inline operator Float *();
			inline operator const Float *() const;

		public:
			Matrix4D &operator=(Matrix4D &&sNewMatrix4D);
			Matrix4D &operator=(const Matrix4D &sNewMatrix4D);
			Matrix4D &operator=(std::array <Float, 4u> &&sNewMatrix4D);
			Matrix4D &operator=(const std::array <Float, 4u> &sNewMatrix4D);

			Void zeroMatrix();
			Void identityMatrix();
			Void transposeMatrix();
			Bool inverseMatrix();
			Void scaleMatrix(Float nNewFactor);
			Void scaleMatrix(Float nNewFactorX, Float nNewFactorY, Float nNewFactorZ);
			Void rotateMatrix(Float nNewAngle, const Float *pNewAxis);
			Void rotateMatrixX(Float nNewAngleX);
			Void rotateMatrixY(Float nNewAngleY);
			Void rotateMatrixZ(Float nNewAngleZ);
			Void translateMatrix(Float nNewTranX, Float nNewTranY, Float nNewTranZ);
			Void perspectiveMatrix(Float nNewAspect, Float nNewFieldOfView, Float nNewNear, Float nNewFar);
			Void orthographicMatrix(Float nNewNear, Float nNewFar, Float nNewTop, Float nNewRight);
			Void multiplyMatrix(Float nNewFactor);
			Void multiplyMatrix(const Float *pNewMatrix);
		};

		inline Matrix4D::operator Float *()
		{
			return this->vElement;
		}

		inline Matrix4D::operator const Float *() const
		{
			return this->vElement;
		}
	}
}

#endif