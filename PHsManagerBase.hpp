
/*
	2016.01.22
	Created by PHJ.
*/

#ifndef _PHS_MANAGER_BASE_HPP

#define _PHS_MANAGER_BASE_HPP

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsManager
	{
		template <class __Manager_Type> __Manager_Type *ManagerBase <__Manager_Type>::p__Manager_Type = nullptr;

		template <class __Manager_Type> inline __Manager_Type &ManagerBase <__Manager_Type>::getManager()
		{
			assert(ManagerBase <__Manager_Type>::p__Manager_Type);
			return *ManagerBase <__Manager_Type>::p__Manager_Type;
		}

		template <class __Manager_Type> Void ManagerBase <__Manager_Type>::initializeManager()
		{
			if(!ManagerBase <__Manager_Type>::p__Manager_Type)
				ManagerBase <__Manager_Type>::p__Manager_Type = new __Manager_Type();
		}

		template <class __Manager_Type> Void ManagerBase <__Manager_Type>::finalizeManager()
		{
			if(ManagerBase <__Manager_Type>::p__Manager_Type)
			{
				delete ManagerBase <__Manager_Type>::p__Manager_Type;
				ManagerBase <__Manager_Type>::p__Manager_Type = nullptr;
			}
		}
	}
}

#endif