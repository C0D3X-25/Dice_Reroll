#pragma once

#include "../capacity_modifiers/SCapacityModifiers.hpp"
#include "../capacity_action/ICapacityAction.hpp"

#include <queue>

namespace capacity {
	class ACapacity {
	public:
		virtual void executeCapacity(void) = 0;

		void pushCapacityModifier(const SCapacityModifiers& cap);
		SCapacityModifiers getNextCapacityModifier(void);
		bool isNextCapacityModifier(void);

	private:
		std::queue<SCapacityModifiers> m_capacities_mod;
	};
}
