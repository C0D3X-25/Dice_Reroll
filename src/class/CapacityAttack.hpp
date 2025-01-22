#pragma once 

#include "tool_lib.hpp"
#include "../struct/CapacityStats.hpp"
#include "../interface/ICapacity.hpp"

#include <iostream>
#include <string>


namespace capacity {
	class CapacityAttack : public ICapacity {
	public:
		CapacityAttack(void) {
			m_name = "Attack";
			m_stats.m_modify_life = -10;
		}
		~CapacityAttack(void) = default;

		void printDebugCapacity(void) override {
			std::cout << "Capacity " << m_name << '\n';
			std::cout << "Modify Life: " << m_stats.m_modify_life << '\n';
			std::cout << "Modify Armor: " << m_stats.m_modify_armor << '\n';
		}

		void printCapacity(void) override {
			std::cout << "Capacity " << m_name << '\n';
		}

		std::string getName(void) const override {
			return m_name;
		}

		CapacityStats getStats(void) const override {
			return m_stats;
		}

	private:
		CapacityStats m_stats;
		std::string m_name{ "N/A" };
	};
} // namespace capacity
