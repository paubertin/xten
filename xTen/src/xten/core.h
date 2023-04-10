#pragma once

#ifdef XT_PLATFORM_WINDOWS
	#ifdef XT_BUILD_DLL
		#define XTEN_API __declspec(dllexport)
	#else
		#define XTEN_API __declspec(dllimport)
	#endif // XT_BUILD_DLL
#else
	#error xTen only supports Windows for now!
#endif // XT_PLATFORM_WINDOWS
