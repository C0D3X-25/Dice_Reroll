#pragma once

#include ".\BaseCapacityAction.hpp"
#include "..\capacity_modifiers\CapacityComponent.hpp"

#include <cstdint>

namespace capacity {

	class CapacityActionHeal : public BaseCapacityAction {
	public:
		CapacityActionHeal(uint8_t heal);

		CapacityComponent doAction(void) override;

	private:
		uint8_t m_heal{ 0 };
	};
}