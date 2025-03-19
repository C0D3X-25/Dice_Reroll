#pragma once 

#include "tool_lib.hpp"
#include "../../include/capacity_modifiers/SCapacityModifiers.hpp"
#include "../../include/capacity/ICapacity.hpp"
#include "../../include/capacity_affectation/ICapacityAffectation.hpp"

#include <iostream>
#include <string>
#include <queue>


namespace capacity {
	class CapacityAttack : public ICapacity {
	public:
		CapacityAttack(void) {
			m_name = "Attack";
			m_stats.m_life = -10;
		}
		~CapacityAttack(void) = default;

		virtual void printDebugCapacity(void) = 0;
		virtual void printCapacity(void) = 0;

		virtual void executeCapacity(void) = 0;

		virtual std::string getName(void) const = 0;

		SCapacityModifiers getStats(void) const override {
			return m_stats;
		}

		void pushCapacityAttributs(const SCapacityModifiers& cap) override {
			m_order_capacity.push(cap);
		}

		SCapacityModifiers& getNextCapacityAttributs(void) const override {

		}

		// Return false if there is 1 element or less
		bool isNextCapacityAttribut(void) const override{
			if (m_order_capacity.size() <= 1) {
				return false;
			}
			return true;
		}

	private:
		std::string m_name{ "N/A" };
		SCapacityModifiers m_stats; // TODO: remove when queue is implement
		std::queue<SCapacityModifiers> m_order_capacity;
	};
} // namespace capacity
