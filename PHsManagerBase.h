
/*
	2016.01.22
	Created by PHJ.
*/

#ifndef _PHS_MANAGER_BASE_H

#define _PHS_MANAGER_BASE_H

#include "PHsCommon.h"

#include <cassert>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsManager
	{
		template <class __Manager_Type> class ManagerBase
		{
		private:
			static __Manager_Type *p__Manager_Type;

		protected:
			ManagerBase() = default;
			ManagerBase(ManagerBase &&sNewManagerBase) = default;
			ManagerBase(const ManagerBase &sNewManagerBase) = default;
			virtual ~ManagerBase() = default;

		public:
			inline static __Manager_Type &getManager();
			static Void initializeManager();
			static Void finalizeManager();
		};
	}
}

#include "PHsManagerBase.hpp"

#endif