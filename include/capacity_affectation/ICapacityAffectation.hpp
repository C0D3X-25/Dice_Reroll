// How a capacity is apply to a targetted IEntity

#pragma once


namespace capacity {
	class ICapacityAffectation {
	public:
		virtual ~ICapacityAffectation(void) = default;

		virtual void receiveCapacity() = 0;
	};
} // namespace capacity
