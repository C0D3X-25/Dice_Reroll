#pragma once 

#include "tool_lib.hpp"
#include "../../include/capacity_modifiers/SCapacityModifiers.hpp"
#include "../../include/capacity/BaseCapacity.hpp"


using capacity::BaseCapacity;
using capacity::SCapacityModifiers;

namespace entity {
	class IEntity {
	public:
		virtual ~IEntity(void) = default;

		virtual void printEntity(void) = 0;

		virtual void useCapacity(BaseCapacity& capacity, IEntity& target) = 0;
		virtual void takeCapacity(const SCapacityModifiers& capacity, const IEntity& src) = 0;

		virtual std::string getName(void) const = 0;
	};
} // namespace entity
