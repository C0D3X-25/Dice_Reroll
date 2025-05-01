#pragma once

#include "BaseCapacityAction.hpp"
#include "..\capacity_modifiers\CapacityModifiersStruct.hpp"

#include <cstdint>
#include <vector>

namespace capacity {

	class CapacityActionDamage : public BaseCapacityAction {
	public:
		CapacityActionDamage(const uint8_t damage, const std::vector<CapacityTargetEnum>& target);

		CapacityModifiersStruct doAction(void) override;

	private:
		CapacityModifiersStruct m_modifier;
		uint8_t m_damage{ 0 };
	};
}
