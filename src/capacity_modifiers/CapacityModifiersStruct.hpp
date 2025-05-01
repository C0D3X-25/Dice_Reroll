#pragma once
#include "../capacity/CapacityEnum.hpp"

#include <cstdint>
#include <vector>

namespace capacity {
	struct CapacityModifiersStruct {

		std::vector<CapacityTargetEnum> m_targets;

		int8_t m_damage{ 0 };
		int8_t m_heal{ 0 };

		int8_t m_add_armor{ 0 };
		int8_t m_remove_armor{ 0 };

		
		// TODO: Status
	};
} // namespace capacity
