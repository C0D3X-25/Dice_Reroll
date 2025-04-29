#pragma once

#include <inttypes.h>

namespace capacity {
	struct CapacityModifiersStruct {

		int8_t m_damage{ 0 };
		int8_t m_heal{ 0 };

		int8_t m_add_armor{ 0 };
		int8_t m_remove_armor{ 0 };

		// TODO: Status
	};
} // namespace capacity
