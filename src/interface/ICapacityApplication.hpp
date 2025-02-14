// How a capacity is apply to a targetted IEntity

#pragma once

#include "tool_lib.hpp"

namespace capacity {
	class ICapacityApplication {
	public:
		virtual ~ICapacityApplication(void) = default;

		virtual void create() = 0;
	};
} // namespace capacity
