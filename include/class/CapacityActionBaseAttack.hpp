// Action who do damage
#pragma once

#include "..\interface\ICapacityAction.hpp"

namespace capacity {
	class CapacityActionBaseAttack : public ICapacityAction {
	public:
		CapacityActionBaseAttack(uint8_t dmg);
		SCapacityModifiers doAction(void) override;
	};
}
