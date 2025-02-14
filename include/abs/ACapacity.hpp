#pragma once

#include "../struct/SCapacityModifiers.hpp"
#include "../interface/ICapacityAction.hpp"

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
