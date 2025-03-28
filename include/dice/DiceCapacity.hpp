#pragma once
#include "ADice.hpp"
#include "IRollAdvantageDisadvantage.hpp"
#include "../capacity/ACapacity.hpp"
#include "../capacity/CapacityNothing.hpp"


namespace dice {
	class ACapacity;
	class CapacityNothing;

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
		CapacityNothing m_empty;
		ACapacity m_sides[10] = {  }; // TODO: Add CapacityNothing to all sides
	};
}
