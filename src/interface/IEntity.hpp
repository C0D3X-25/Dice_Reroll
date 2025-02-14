#pragma once 

#include "tool_lib.hpp"
#include "../struct/CapacityAttributs.hpp"
#include "ICapacity.hpp"


using capacity::ICapacity;
using capacity::SCapacityModifiers;

namespace entity {
	class IEntity {
	public:
		virtual ~IEntity(void) = default;

		virtual void printEntity(void) = 0;

		virtual void useCapacity(ICapacity& capacity, IEntity& target) = 0;
		virtual void takeCapacity(const SCapacityModifiers& capacity, const IEntity& src) = 0;

		virtual std::string getName(void) const = 0;
	};
} // namespace entity
