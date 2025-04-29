#pragma once

#include "../capacity_modifiers/CapacityModifiersStruct.hpp"
#include "../capacity_action/ICapacityAction.hpp"

#include <queue>
#include <string>

namespace capacity {
	class BaseCapacity {
	public:
		BaseCapacity(void) = default;
		virtual ~BaseCapacity(void) = default;


		std::queue<CapacityModifiersStruct> getAllCapacityModifiers(void) {
			return m_capacities_mod;
		}


		void queueCapacityModifier(const CapacityModifiersStruct& capacity_mod) {
			m_capacities_mod.push(capacity_mod);
		}


		CapacityModifiersStruct getNextCapacityModifier(void) {
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


		std::string_view getName(void) const { return m_name; }

	protected:
		std::string m_name{ "N/A" };
		std::queue<CapacityModifiersStruct> m_capacities_mod;

	private:
		CapacityModifiersStruct m_current_mod;
	};
}
