#pragma once

#include <cstdint>
#include <iostream>

namespace attribute {

	constexpr int8_t MIN_STAT_VALUE{ -10 };

	/// <summary>
	/// Struct to hold the stats of an entity.
	/// Minimum value is 1.
	/// </summary>
	struct Attribute {

		void printAllAttributes(void) const {
			std::cout
				<< "STR: " << static_cast<int>(m_strength) << '\n'
				<< "DEX: " << static_cast<int>(m_dexterity) << '\n'
				<< "CON: " << static_cast<int>(m_constitution) << '\n'
				<< "INT: " << static_cast<int>(m_intelligence) << '\n'
				<< "WIS: " << static_cast<int>(m_wisdom) << '\n'
				<< "CHA: " << static_cast<int>(m_charisma) << '\n';
		}

		void setStrength(int8_t value) { value > MIN_STAT_VALUE ? m_strength = value : MIN_STAT_VALUE; }
		void setDexterity(int8_t value) { value > MIN_STAT_VALUE ? m_dexterity = value : MIN_STAT_VALUE; }
		void setConstitution(int8_t value) { value > MIN_STAT_VALUE ? m_constitution = value : MIN_STAT_VALUE; }
		void setIntelligence(int8_t value) { value > MIN_STAT_VALUE ? m_intelligence = value : MIN_STAT_VALUE; }
		void setWisdom(int8_t value) { value > MIN_STAT_VALUE ? m_wisdom = value : MIN_STAT_VALUE; }
		void setCharisma(int8_t value) { value > MIN_STAT_VALUE ? m_charisma = value : MIN_STAT_VALUE; }

		int8_t getStrength(void) const { return m_strength; }
		int8_t getDexterity(void) const { return m_dexterity; }
		int8_t getConstitution(void) const { return m_constitution; }
		int8_t getIntelligence(void) const { return m_intelligence; }
		int8_t getWisdom(void) const { return m_wisdom; }
		int8_t getCharisma(void) const { return m_charisma; }

	private:
		int8_t m_strength{ MIN_STAT_VALUE };
		int8_t m_dexterity{ MIN_STAT_VALUE };
		int8_t m_constitution{ MIN_STAT_VALUE };
		int8_t m_intelligence{ MIN_STAT_VALUE };
		int8_t m_wisdom{ MIN_STAT_VALUE };
		int8_t m_charisma{ MIN_STAT_VALUE };
	};
} // namespace stat
