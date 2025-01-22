#pragma once 

#include "tool_lib.hpp"
#include "../struct/CapacityStats.hpp"

namespace capacity {
	struct CapacityStats;

	class ICapacity {
	public:
		virtual ~ICapacity(void) = default;
		
		virtual void printDebugCapacity(void) = 0;
		virtual void printCapacity(void) = 0;

		virtual std::string getName(void) const = 0;
		virtual CapacityStats getStats(void) const = 0;
	};
} // namespace capacity
