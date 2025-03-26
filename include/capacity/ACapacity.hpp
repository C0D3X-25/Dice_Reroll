#pragma once

#include "../capacity_modifiers/SCapacityModifiers.hpp"
#include "../capacity_action/ICapacityAction.hpp"

#include <queue>
#include <string>

namespace capacity {
	class ACapacity {
	public:
		virtual ~ACapacity(void) = default;


		virtual void executeCapacity(void) = 0;


		void pushCapacityModifier(const SCapacityModifiers& capacity_mod) {
			m_capacities_mod.push(capacity_mod);
		}


		SCapacityModifiers getNextCapacityModifier(void) {
			m_current_mod = m_capacities_mod.front();
			m_capacities_mod.pop();
			return m_current_mod;
		}


		bool isNextCapacityModifier(void) {
			if (m_capacities_mod.size() <= 1) {
				return false;
			}
			return true;
		}


		std::string getName(void) const {
			return m_name;
		}

	protected:
		std::string m_name{ "N/A" };
		std::queue<SCapacityModifiers> m_capacities_mod;

	private:
		SCapacityModifiers m_current_mod;
	};
}
