#pragma once

#include "../capacity_modifiers/CapacityModifiersStruct.hpp"
#include "../capacity_action/BaseCapacityAction.hpp"
#include "../capacity/CapacityEnum.hpp"

#include <queue>
#include <string>
#include <vector>
#include <iostream>

namespace capacity {

	class BaseCapacity {
	public:
		virtual ~BaseCapacity(void) = default;


		std::queue<CapacityModifiersStruct> getAllCapacityModifiers(void) {
			return m_capacity_modifiers;
		}


		void queueCapacityModifier(const CapacityModifiersStruct& capacity_modifier) {
			addCapacityTarget(capacity_modifier);
			m_capacity_modifiers.push(capacity_modifier);
		}


		const CapacityModifiersStruct& getNextCapacityModifier(void) {
			if (!m_capacity_modifiers.empty()) {
				m_current_modifier = m_capacity_modifiers.front();
				m_capacity_modifiers.pop();
				return m_current_modifier;
			}
			return CapacityModifiersStruct{};
		}


		bool isNextCapacityModifier(void) {
			return m_capacity_modifiers.size() > 1;
		}


		void printCapacity(void) const {
			std::cout << "Capacity name:     - " << getCapacityName()
				<< " -\n";
			std::cout << "Capacity purposes: [ ";
			for (const auto& purpose : m_capacity_purpose) {
				std::cout << toString(purpose) << " ";
			}
			std::cout << "]\n";
			std::cout << "Capacity targets:  [ ";
			for (const auto& target : m_capacity_target) {
				std::cout << toString(target) << " ";
			}
			std::cout << "]\n";
			std::cout << "Capacity triggers: [ ";
			for (const auto& trigger : m_capacity_trigger) {
				std::cout << toString(trigger) << " ";
			}
			std::cout << "]\n";
		}


		void setEntityName(const std::string& name)								{ m_name = name; }
		void setCapacityPurposes(const std::vector<CapacityPurposeEnum>& purpose)	{ m_capacity_purpose = purpose; }
		void setCapacityTriggers(const std::vector<CapacityTriggerEnum>& trigger)	{ m_capacity_trigger = trigger; }
		
		std::string getCapacityName(void) const								{ return m_name; }
		std::vector<CapacityPurposeEnum> getCapacityPurposes(void) const	{ return m_capacity_purpose; }
		std::vector<CapacityTargetEnum> getCapacityTargets(void) const		{ return m_capacity_target; }
		std::vector<CapacityTriggerEnum> getCapacityTriggers(void) const	{ return m_capacity_trigger; }

	private:
		std::string m_name{ "N/A" };
		std::queue<CapacityModifiersStruct> m_capacity_modifiers;
		CapacityModifiersStruct m_current_modifier;
		std::vector<CapacityPurposeEnum> m_capacity_purpose;
		std::vector<CapacityTargetEnum> m_capacity_target;
		std::vector<CapacityTriggerEnum> m_capacity_trigger;

	private:

		void addCapacityTarget(const CapacityModifiersStruct& capacity_modifier) {
			for (const auto& target : capacity_modifier.m_targets) {
				if (std::find(m_capacity_target.begin(), m_capacity_target.end(), target) == m_capacity_target.end()) {
					m_capacity_target.push_back(target);
				}
			}
		}
	};
}
