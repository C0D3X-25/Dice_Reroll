#pragma once

#include "../capacity_modifiers/CapacityModifiersStruct.hpp"
#include "../capacity_action/BaseCapacityAction.hpp"
#include "../capacity/ECapacity.hpp"

#include <queue>
#include <string>
#include <string_view>
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


		const CapacityModifiersStruct getNextCapacityModifier(void) {
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
			std::cout << " - " << getCapacityName()
				<< " - \n" << getCapacityDescription() << '\n';
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

		bool isEmpty(void) const { return m_capacity_modifiers.empty(); }

		void setCapacityName(const std::string& name)							{ m_name = name; }
		void setCapacityDescription(const std::string& description)				{ m_description = description; }
		void setCapacityPurposes(const std::vector<ECapacityPurpose>& purpose)	{ m_capacity_purpose = purpose; }
		void setCapacityTriggers(const std::vector<ECapacityTrigger>& trigger)	{ m_capacity_trigger = trigger; }
		
		std::string_view getCapacityName(void) const					{ return m_name; }
		std::string_view getCapacityDescription(void) const				{ return m_description; }
		std::vector<ECapacityPurpose> getCapacityPurposes(void) const	{ return m_capacity_purpose; }
		std::vector<ECapacityTarget> getCapacityTargets(void) const		{ return m_capacity_target; }
		std::vector<ECapacityTrigger> getCapacityTriggers(void) const	{ return m_capacity_trigger; }

	private:
		void addCapacityTarget(const CapacityModifiersStruct& capacity_modifier) {
			for (const auto& target : capacity_modifier.m_targets) {
				if (std::find(m_capacity_target.begin(), m_capacity_target.end(), target) == m_capacity_target.end()) {
					m_capacity_target.push_back(target);
				}
			}
		}

	private:
		std::string m_name{ "N/A" };
		std::string m_description{ "N/A" };
		std::queue<CapacityModifiersStruct> m_capacity_modifiers;
		CapacityModifiersStruct m_current_modifier;
		std::vector<ECapacityPurpose> m_capacity_purpose;
		std::vector<ECapacityTarget> m_capacity_target;
		std::vector<ECapacityTrigger> m_capacity_trigger;
	};
}
