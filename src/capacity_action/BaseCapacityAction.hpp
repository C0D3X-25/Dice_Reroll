#pragma once

#include "../capacity_modifiers/CapacityModifiersStruct.hpp"
#include "../capacity/CapacityEnum.hpp"

#include <vector>
#include <string>

namespace capacity {

	class BaseCapacityAction {
	public:
		BaseCapacityAction(const std::vector<CapacityTargetEnum>& targets) 
			: m_targets(targets) {}
		virtual ~BaseCapacityAction(void) = default;

		virtual CapacityModifiersStruct doAction(void) {
			m_modifier.m_targets = m_targets;
			return m_modifier;
		}

		virtual std::vector<CapacityTargetEnum> getTargets(void) const { return m_targets; }

	private:
		CapacityModifiersStruct m_modifier;
		std::vector<CapacityTargetEnum> m_targets;
	};
}