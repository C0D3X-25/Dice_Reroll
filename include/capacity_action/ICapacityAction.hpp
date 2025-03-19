// Interface to represent what a Capacity Action must implement
#pragma once

#include "../capacity_modifiers/SCapacityModifiers.hpp"

namespace capacity {
	class ICapacityAction {
	public:
		virtual SCapacityModifiers doAction(void) = 0;
	};
}