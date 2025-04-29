// Action who do damage
#pragma once

#include "ICapacityAction.hpp"
#include "..\capacity_modifiers\CapacityModifiersStruct.hpp"

namespace capacity {
	class CapacityActionAttack : public ICapacityAction {
	public:
		CapacityActionAttack(uint8_t damage);

		CapacityModifiersStruct doAction(void) override;

	private:
		uint8_t m_damage{ 0 };
	};
}
