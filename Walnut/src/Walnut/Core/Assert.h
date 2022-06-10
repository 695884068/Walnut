#pragma once

#include "Walnut/Core/Base.h"
#include "Walnut/Core/Log.h"
#include <filesystem>

#ifdef WN_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define WN_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { WN##type##ERROR(msg, __VA_ARGS__); WN_DEBUGBREAK(); } }
	#define WN_INTERNAL_ASSERT_WITH_MSG(type, check, ...) WN_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define WN_INTERNAL_ASSERT_NO_MSG(type, check) WN_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", WN_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define WN_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define WN_INTERNAL_ASSERT_GET_MACRO(...) WN_EXPAND_MACRO( WN_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, WN_INTERNAL_ASSERT_WITH_MSG, WN_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define WN_ASSERT(...) WN_EXPAND_MACRO( WN_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define WN_CORE_ASSERT(...) WN_EXPAND_MACRO( WN_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define WN_ASSERT(...)
	#define WN_CORE_ASSERT(...)
#endif
