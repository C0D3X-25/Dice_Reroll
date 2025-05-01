#pragma once

#include ".\BaseCapacityAction.hpp"
#include "..\capacity_modifiers\CapacityModifiersStruct.hpp"

#include <cstdint>

namespace capacity {
	class CapacityActionAddArmor : public BaseCapacityAction {
	public:
		CapacityActionAddArmor(uint8_t armor, CapacityTargetEnum target);
		CapacityModifiersStruct doAction(void) override;

	private:
		uint8_t m_armor{ 0 };
		CapacityTargetEnum m_target{ };
	};
}