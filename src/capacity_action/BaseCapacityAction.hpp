#pragma once

#include "../capacity_modifiers/CapacityComponent.hpp"
#include "../capacity/ECapacity.hpp"

#include <vector>
#include <string>

namespace capacity {

	class BaseCapacityAction {
	public:
		BaseCapacityAction(const std::vector<ECapacityTarget>& targets) 
			: m_targets(targets) {}
		virtual ~BaseCapacityAction(void) = default;

		virtual CapacityComponent doAction(void) {
			m_modifier.m_targets = m_targets;
			return m_modifier;
		}

		virtual std::vector<ECapacityTarget> getTargets(void) const { return m_targets; }

	private:
		CapacityComponent m_modifier;
		std::vector<ECapacityTarget> m_targets;
	};
}