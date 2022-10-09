#pragma once
#ifdef LEAF_PLATFORM_WINDOWS
#ifdef LEAF_BUILD_DLL
#define LEAF_API __declspec(dllexport)
#else
#define LEAF_API __declspec(dllimport)
#endif
#else
#error Leaf only support Winodws!
#endif

#define BIT(x) (1 << x)
