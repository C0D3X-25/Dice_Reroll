// Action who do damage
#pragma once

#include "ICapacityAction.hpp"
#include "..\capacity_modifiers\CapacityModifiersStruct.hpp"

#include <cstdint>

namespace capacity {
	class CapacityActionDamage : public ICapacityAction {
	public:
		CapacityActionDamage(uint8_t damage);

		CapacityModifiersStruct doAction(void) override;

	private:
		uint8_t m_damage{ 0 };
	};
}
