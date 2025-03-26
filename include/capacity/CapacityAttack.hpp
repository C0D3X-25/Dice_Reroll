#pragma once 

#include "ACapacity.hpp"
#include "../capacity_action/CapacityActionBaseAttack.hpp"


namespace capacity {
	class CapacityPlayerSingleAttack : public ACapacity {
	public:
		CapacityPlayerSingleAttack(void) {
			m_name = "Attack";
			CapacityActionBaseAttack attack(5);
			pushCapacityModifier(attack.doAction());
		}
		~CapacityPlayerSingleAttack(void) = default;

		virtual void executeCapacity(void) = 0;
	};
} // namespace capacity
