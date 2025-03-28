#pragma once

#include "ACapacity.hpp"

namespace capacity {
	// Capacity that does nothing, this is the default capacity of any side of CapacityDice
	class CapacityNothing : ACapacity {
	public:
		CapacityNothing(void);
		~CapacityNothing(void) = default;
	};
}
