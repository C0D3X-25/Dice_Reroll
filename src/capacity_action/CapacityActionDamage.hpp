#pragma once

#include "BaseCapacityAction.hpp"
#include "..\capacity_modifiers\CapacityComponent.hpp"

#include <cstdint>
#include <vector>

namespace capacity {

	class CapacityActionDamage : public BaseCapacityAction {
	public:
		CapacityActionDamage(const uint8_t damage, const std::vector<ECapacityTarget>& target);

		CapacityComponent doAction(void) override;

	private:
		CapacityComponent m_modifier;
		uint8_t m_damage{ 0 };
	};
}
