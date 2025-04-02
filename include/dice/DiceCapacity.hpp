#pragma once
#include "ADice.hpp"
#include "IRollAdvantageDisadvantage.hpp"
#include "../capacity/BaseCapacity.hpp"
#include "../capacity/CapacityNothing.hpp"

#include <array>
#include <memory>

namespace capacity {
	class BaseCapacity;
	class CapacityNothing;
}

namespace dice {
	using capacity::BaseCapacity;
	using capacity::CapacityNothing;

	// Dice holding the capacites of an entity. Set to 10 sides	 
	class DiceCapacity: ADice, IRollAdvantageDisadvantage {
	public:
		DiceCapacity(void);

		DiceCapacity(const BaseCapacity& capacity);
		~DiceCapacity(void) = default;


		void setCapacity(const BaseCapacity& capacity);
		const std::shared_ptr<BaseCapacity> getCapacity(const uint8_t index) const;


		// Inherited via IRollAdvantageDisadvantage
		uint16_t rollAdvantage(void) override;
		uint16_t rollDisadvantage(void) override;

		// Inherited via ADice
		void roll(void) override;
		void printDice(void) override;

		static constexpr uint8_t m_SIDES_COUNT = 10;

	private:
		std::shared_ptr<BaseCapacity> m_empty = std::make_shared<CapacityNothing>();
		//BaseCapacity* m_empty = new CapacityNothing;
		//std::array<BaseCapacity**, m_SIDES_COUNT> m_sides{};
		std::array<std::shared_ptr<BaseCapacity>, m_SIDES_COUNT> m_sides {};
	};
}