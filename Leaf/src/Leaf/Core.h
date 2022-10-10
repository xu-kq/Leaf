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

#ifdef LEAF_ENABLE_ASSERTS
#define LEAF_ASSERT(x, ...)                             \
  {                                                     \
    if (!(x)) {                                         \
      LEAF_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
      __debugbreak();                                   \
    }                                                   \
  }
#define LEAF_CORE_ASSERT(x, ...)                             \
  {                                                          \
    if (!(x)) {                                              \
      LEAF_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
      __debugbreak();                                        \
    }                                                        \
  }
#else
#define LEAF_ASSERT(x, ...)
#define LEAF_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
