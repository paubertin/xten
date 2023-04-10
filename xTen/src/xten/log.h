#pragma once

#include <memory>
#include "core.h"
#include "spdlog/spdlog.h"

namespace xten {

	class XTEN_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};

}

// core logger

template<class... Args>
constexpr auto XT_CORE_FATAL(const Args&... args) { return ::xten::Log::getCoreLogger()->critical(args...); }

template<class... Args>
constexpr auto XT_CORE_ERROR(const Args&... args) { return ::xten::Log::getCoreLogger()->error(args...); }

template<class... Args>
constexpr auto XT_CORE_WARN(const Args&... args) { return ::xten::Log::getCoreLogger()->warn(args...); }

template<class... Args>
constexpr auto XT_CORE_INFO(const Args&... args) { return ::xten::Log::getCoreLogger()->info(args...); }

template<class... Args>
constexpr auto XT_CORE_TRACE(const Args&... args) { return ::xten::Log::getCoreLogger()->trace(args...); }

// client logger

template<class... Args>
constexpr auto XT_FATAL(const Args&... args) { return ::xten::Log::getClientLogger()->critical(args...); }

template<class... Args>
constexpr auto XT_ERROR(const Args&... args) { return ::xten::Log::getClientLogger()->error(args...); }

template<class... Args>
constexpr auto XT_WARN(const Args&... args) { return ::xten::Log::getClientLogger()->warn(args...); }

template<class... Args>
constexpr auto XT_INFO(const Args&... args) { return ::xten::Log::getClientLogger()->info(args...); }

template<class... Args>
constexpr auto XT_TRACE(const Args&... args) { return ::xten::Log::getClientLogger()->trace(args...); }