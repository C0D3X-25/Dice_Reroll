// Action who do damage
#pragma once

#include ".\ICapacityAction.hpp"
#include "..\capacity_modifiers\SCapacityModifiers.hpp"

namespace capacity {
	class CapacityActionBaseAttack : public ICapacityAction {
	public:
		CapacityActionBaseAttack(uint8_t dmg);

		SCapacityModifiers doAction(void) override;

	private:
		uint8_t m_dmg{ 0 };
	};
}
