#pragma once

#include "BaseCapacityAction.hpp"
#include "..\capacity_modifiers\CapacityModifiersStruct.hpp"

#include <cstdint>

namespace capacity {

	class CapacityActionRemoveArmor : public BaseCapacityAction {
	public:
		CapacityActionRemoveArmor(uint8_t armor);

		CapacityModifiersStruct doAction(void) override;

	private:
		uint8_t m_armor{ 0 };
	};
}
