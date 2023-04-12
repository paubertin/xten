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

constexpr auto BIT(int x) { return (1 << x); }

#ifdef XT_ENABLE_ASSERTS
	#define XT_ASSERT(x, ...) { if (!(x)) { XT_ERROR("Assertion failed: ${0}", __VA_ARGS__); __debugbreak(); } }
	#define XT_CORE_ASSERT(x, ...) { if (!(x)) { XT_CORE_ERROR("Assertion failed: ${0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define XT_ASSERT(x, ...)
	#define XT_CORE_ASSERT(x, ...)
#endif // XT_ENABLE_ASSERTS
