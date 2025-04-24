// Action who do damage
#pragma once

#include "ICapacityAction.hpp"
#include "..\capacity_modifiers\SCapacityModifiers.hpp"

namespace capacity {
	class CapacityActionAttack : public ICapacityAction {
	public:
		CapacityActionAttack(uint8_t damage);

		SCapacityModifiers doAction(void) override;

	private:
		uint8_t m_damage{ 0 };
	};
}
