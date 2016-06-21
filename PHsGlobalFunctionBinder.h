
/*
	2016.01.22
	Created by PHJ.
*/

#ifndef _PHS_GLOBAL_FUNCTION_BINDER_H

#define _PHS_GLOBAL_FUNCTION_BINDER_H

#include "PHsCommon.h"

#include <cassert>
#include <functional>
#include <utility>

namespace PHs
{
	/*
		TODO : Place your code here
	*/
	
	inline namespace PHsUtility
	{
		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg> class GlobalFunctionBinderCDecl
		{
		public:
			using GlobalFunc = std::function <__Global_Function_Return(__Global_Function_Arg...)>;
			using MemberFunc = std::function <__Global_Function_Return(__Function_Class *, __Global_Function_Arg...)>;

		private:
			static MemberFunc fMemberFunc;
			static __Function_Class *pClassInstance;

		private:
			inline GlobalFunctionBinderCDecl() = delete;
			GlobalFunctionBinderCDecl(GlobalFunctionBinderCDecl &&sNewGlobalFunctionBinderCDecl) = delete;
			GlobalFunctionBinderCDecl(const GlobalFunctionBinderCDecl &sNewGlobalFunctionBinderCDecl) = delete;
			~GlobalFunctionBinderCDecl() = delete;

		public:
			inline static Void bindMemberFunc(MemberFunc fNewMemberFunc);
			inline static Void bindClassInstance(__Function_Class *pNewClassInstance);
			inline static __Global_Function_Return __cdecl Function(__Global_Function_Arg ...sFuncArg);
		};

		template <class __Function_Class, class __Global_Function_Return, class ...__Global_Function_Arg> class GlobalFunctionBinderStdCall
		{
		public:
			using GlobalFunc = std::function <__Global_Function_Return(__Global_Function_Arg...)>;
			using MemberFunc = std::function <__Global_Function_Return(__Function_Class *, __Global_Function_Arg...)>;

		private:
			static MemberFunc fMemberFunc;
			static __Function_Class *pClassInstance;

		private:
			inline GlobalFunctionBinderStdCall() = delete;
			GlobalFunctionBinderStdCall(GlobalFunctionBinderStdCall &&sNewGlobalFunctionBinderStdCall) = delete;
			GlobalFunctionBinderStdCall(const GlobalFunctionBinderStdCall &sNewGlobalFunctionBinderStdCall) = delete;
			~GlobalFunctionBinderStdCall() = delete;

		public:
			inline static Void bindMemberFunc(MemberFunc fNewMemberFunc);
			inline static Void bindClassInstance(__Function_Class *pNewClassInstance);
			inline static __Global_Function_Return __stdcall Function(__Global_Function_Arg ...sFuncArg);
		};
	}
}

#include "PHsGlobalFunctionBinder.hpp"

#endif