#pragma once

#include ".\BaseCapacityAction.hpp"
#include "..\capacity_modifiers\CapacityModifiersStruct.hpp"

#include <cstdint>

namespace capacity {

	class CapacityActionHeal : public BaseCapacityAction {
	public:
		CapacityActionHeal(uint8_t heal);

		CapacityModifiersStruct doAction(void) override;

	private:
		uint8_t m_heal{ 0 };
	};
}