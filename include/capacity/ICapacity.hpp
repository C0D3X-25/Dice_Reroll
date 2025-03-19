#pragma once 

#include "tool_lib.hpp"
#include "../../include/capacity_modifiers/SCapacityModifiers.hpp"

namespace capacity {
	struct SCapacityModifiers;

	class ICapacity {
	public:
		virtual ~ICapacity(void) = default;
		
		// Debug
		virtual void printDebugCapacity(void) = 0;
		virtual void printCapacity(void) = 0;

		// 
		virtual void executeCapacity(void) = 0;
		virtual std::string getName(void) const = 0;

		virtual SCapacityModifiers getStats(void) const = 0; // TODO: delete when queue is implement

		// std::queue management
		virtual void pushCapacityAttributs(const SCapacityModifiers& cap) = 0;
		virtual SCapacityModifiers& getNextCapacityAttributs(void) const = 0;
		virtual bool isNextCapacityAttribut(void) const = 0;
	};
} // namespace capacity
