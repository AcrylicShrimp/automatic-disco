
/*
	2016.01.22
	Created by PHJ.
*/

#ifndef _PHS_GLOBAL_FUNCTION_BINDER_HPP

#define _PHS_GLOBAL_FUNCTION_BINDER_HPP

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsUtility
	{
		/*
			For __cdecl
		*/
		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg>
		typename GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::MemberFunc GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::fMemberFunc;

		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg>
		__Function_Class *GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::pClassInstance = nullptr;

		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg>
		inline Void GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::bindMemberFunc(typename GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::MemberFunc fNewMemberFunc)
		{
			GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::fMemberFunc = fNewMemberFunc;
		}

		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg>
		inline Void GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::bindClassInstance(__Function_Class *pNewClassInstance)
		{
			GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::pClassInstance = pNewClassInstance;
		}

		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg>
		inline __Global_Function_Return __cdecl GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::Function(__Global_Function_Arg ...sFuncArg)
		{
			assert((GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::pClassInstance));
			return GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::fMemberFunc(GlobalFunctionBinderCDecl <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::pClassInstance, std::forward <__Global_Function_Arg>(sFuncArg)...);
		}

		/*
			For __stdcall
		*/
		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg>
		typename GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::MemberFunc GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::fMemberFunc;

		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg>
		__Function_Class *GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::pClassInstance = nullptr;

		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg>
		inline Void GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::bindMemberFunc(typename GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::MemberFunc fNewMemberFunc)
		{
			GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::fMemberFunc = fNewMemberFunc;
		}

		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg>
		inline Void GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::bindClassInstance(__Function_Class *pNewClassInstance)
		{
			GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::pClassInstance = pNewClassInstance;
		}

		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg>
		inline __Global_Function_Return __stdcall GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::Function(__Global_Function_Arg ...sFuncArg)
		{
			assert((GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::pClassInstance));
			return GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::fMemberFunc(GlobalFunctionBinderStdCall <__Function_Class, __Global_Function_Return, __Global_Function_Arg...>::pClassInstance, std::forward <__Global_Function_Arg>(sFuncArg)...);
		}
	}
}

#endif