#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
namespace Leaf {
class LEAF_API Log {
 public:
  static void Init();

  static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
    return s_CoreLogger;
  }
  static std::shared_ptr<spdlog::logger>& GetClientLogger() {
    return s_ClientLogger;
  }

 private:
  static std::shared_ptr<spdlog::logger> s_CoreLogger;
  static std::shared_ptr<spdlog::logger> s_ClientLogger;
};
}  // namespace Leaf

// Core log macros
#define LEAF_CORE_TRACE(...) ::Leaf::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LEAF_CORE_INFO(...) ::Leaf::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LEAF_CORE_WARN(...) ::Leaf::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LEAF_CORE_ERROR(...) ::Leaf::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LEAF_CORE_FATAL(...) ::Leaf::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define LEAF_TRACE(...) ::Leaf::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LEAF_INFO(...) ::Leaf::Log::GetClientLogger()->info(__VA_ARGS__)
#define LEAF_WARN(...) ::Leaf::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LEAF_ERROR(...) ::Leaf::Log::GetClientLogger()->error(__VA_ARGS__)
#define LEAF_FATAL(...) ::Leaf::Log::GetClientLogger()->critical(__VA_ARGS__)


// if is a distribution version, set it to none would be fine
// #define LEAF_TRACE(...)