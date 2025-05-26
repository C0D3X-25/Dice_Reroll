#pragma once

#include ".\BaseCapacityAction.hpp"
#include "..\capacity_modifiers\CapacityComponent.hpp"

#include <cstdint>

namespace capacity {
	class CapacityActionAddArmor : public BaseCapacityAction {
	public:
		CapacityActionAddArmor(uint8_t armor, ECapacityTarget target);
		CapacityComponent doAction(void) override;

	private:
		uint8_t m_armor{ 0 };
		ECapacityTarget m_target{ };
	};
}