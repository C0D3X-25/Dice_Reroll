#include "DiceCapacity.hpp"


using namespace dice;

dice::DiceCapacity::DiceCapacity(void) {
    for (uint8_t i = 1; i <= m_SIDES_COUNT; ++i) {
        m_sides[i] = std::make_shared<CapacityNothing>();
    }
}


void DiceCapacity::setCapacity(const std::shared_ptr<BaseCapacity> capacity, const uint8_t side) {
    m_sides.find(side)->second = capacity;
}


const std::shared_ptr<BaseCapacity> DiceCapacity::getCapacity(const uint8_t side) const {
	return m_sides.find(side)->second;
}


const std::shared_ptr<BaseCapacity> DiceCapacity::roll(void) {
    return m_sides.find(getRandomInteger(m_SIDES_COUNT))->second;
}


void DiceCapacity::printDice(void) {
    for (const auto& [side, capacity] : m_sides) {
        std::cout << "Side: " << static_cast<int>(side) << " => " << capacity->getName() << std::endl;
    }
}


const std::shared_ptr<BaseCapacity> DiceCapacity::rollAdvantage(void) {
	// TODO: Return the capacity with the highest rarity
    return 0;
}


const std::shared_ptr<BaseCapacity> DiceCapacity::rollDisadvantage(void) {
	// TODO: Return the capacity with the highest rarity
    return 0;
}

