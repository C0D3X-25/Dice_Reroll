#pragma once

#include ".\ICapacityAction.hpp"
#include "..\capacity_modifiers\CapacityModifiersStruct.hpp"

#include <cstdint>

namespace capacity {
	class CapacityActionAddArmor : public ICapacityAction {
	public:
		CapacityActionAddArmor(uint8_t armor);
		CapacityModifiersStruct doAction(void) override;

	private:
		uint8_t m_armor{ 0 };
	};
}