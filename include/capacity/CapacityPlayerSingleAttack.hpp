#pragma once 

#include "BaseCapacity.hpp"
#include "../capacity_action/CapacityActionAttack.hpp"


namespace capacity {
	class CapacityPlayerSingleAttack : public BaseCapacity {
	public:
		CapacityPlayerSingleAttack(void) {
			m_name = "Attack";
			CapacityActionAttack attack(5);
			queueCapacityModifier(attack.doAction());
		}
		~CapacityPlayerSingleAttack(void) = default;
	};
} // namespace capacity
