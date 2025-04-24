#pragma once 

#include "BaseCapacity.hpp"
#include "../capacity_action/CapacityActionBaseAttack.hpp"


namespace capacity {
	class CapacityPlayerSingleAttack : public BaseCapacity {
	public:
		CapacityPlayerSingleAttack(void) {
			m_name = "Attack";
			CapacityActionBaseAttack attack(5);
			queueCapacityModifier(attack.doAction());
		}
		~CapacityPlayerSingleAttack(void) = default;
	};
} // namespace capacity
