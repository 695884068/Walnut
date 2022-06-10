#pragma once

#include <memory>

#include "Walnut/Core/PlatformDetection.h"

#ifdef WN_DEBUG
	#if defined(WN_PLATFORM_WINDOWS)
		#define WN_DEBUGBREAK() __debugbreak()
	#elif defined(WN_PLATFORM_LINUX)
		#include <signal.h>
		#define WN_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define WN_ENABLE_ASSERTS
#else
	#define WN_DEBUGBREAK()
#endif

#define WN_EXPAND_MACRO(x) x
#define WN_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define WN_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Walnut {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Walnut/Core/Log.h"
#include "Walnut/Core/Assert.h"
