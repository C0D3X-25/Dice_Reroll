#pragma once 

#include "tool_lib.hpp"
#include "../struct/CapacityStats.hpp"
#include "ICapacity.hpp"


using capacity::ICapacity;
using capacity::CapacityStats;

namespace entity {
	class IEntity {
	public:
		virtual ~IEntity(void) = default;

		virtual void printEntity(void) = 0;

		virtual void useCapacity(ICapacity& capacity, IEntity& target) = 0;
		virtual void takeCapacity(const CapacityStats& capacity, const IEntity& src) = 0;

		virtual std::string getName(void) const = 0;
	};
} // namespace entity
