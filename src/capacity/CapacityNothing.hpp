#pragma once

#include "BaseCapacity.hpp"

namespace capacity {
	// Capacity that does nothing, this is the default capacity of any side of CapacityDice
	class CapacityNothing : public BaseCapacity {
	public:
		CapacityNothing(void);
		~CapacityNothing(void) = default;
	};
}
