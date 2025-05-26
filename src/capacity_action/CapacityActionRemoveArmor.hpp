#pragma once

#include "BaseCapacityAction.hpp"
#include "..\capacity_modifiers\CapacityComponent.hpp"

#include <cstdint>

namespace capacity {

	class CapacityActionRemoveArmor : public BaseCapacityAction {
	public:
		CapacityActionRemoveArmor(uint8_t armor);

		CapacityComponent doAction(void) override;

	private:
		uint8_t m_armor{ 0 };
	};
}
