#pragma once
#include "../capacity/ECapacity.hpp"

#include <cstdint>
#include <vector>

namespace capacity {
	struct CapacityComponent {

		std::vector<ECapacityTarget> m_targets;

		int8_t m_damage{ 0 };
		int8_t m_heal{ 0 };

		int8_t m_add_armor{ 0 };
		int8_t m_remove_armor{ 0 };

		
		// TODO: Status
	};
} // namespace capacity
