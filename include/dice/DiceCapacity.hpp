#pragma once
#include "ADice.hpp"
#include "IRollAdvantageDisadvantage.hpp"
#include "../capacity/ACapacity.hpp"


namespace dice {
	class ACapacity;

	// Dice holding the capacites of an entity. Set to 10 sides
	class DiceCapacity: ADice,  IRollAdvantageDisadvantage{
	public:
		DiceCapacity(void) = default;
		DiceCapacity(const ACapacity& capacity);
		~DiceCapacity(void) = default;

		void setCapacity(const ACapacity& capacity);
		ACapacity getCapacity(const uint8_t index) const;

		// Inherited via IRollAdvantageDisadvantage
		uint16_t rollAdvantage(void) override;
		uint16_t rollDisadvantage(void) override;

		// Inherited via ADice
		void roll(void) override;
		void printDice(void) override;

	private:
		ACapacity m_sides[10] = { 0 };
	};
}
