#include "DiceCapacity.hpp"


using namespace dice;

dice::DiceCapacity::DiceCapacity(void) {
    for (uint8_t i = 1; i <= m_SIDES_COUNT; ++i) {
        m_sides[i] = std::make_shared<CapacityNothing>();
    }
}


void DiceCapacity::setCapacity(const std::shared_ptr<BaseCapacity> sp_capacity, const uint8_t side) {
    m_sides.find(side)->second = sp_capacity;
}


const std::shared_ptr<BaseCapacity> DiceCapacity::getCapacity(const uint8_t side) const {
	return m_sides.find(side)->second;
}


//#pragma warning(push)
//#pragma warning(disable: 4244) // Disable warning about possible data loss
//const BaseCapacity& DiceCapacity::roll(void) {
//    return m_sides.find(getRandomValue(m_SIDES_COUNT))->second;
//}
//#pragma warning(pop)  // Restore warning settings


void DiceCapacity::printDice(void) {
    for (const auto& [side, capacity] : m_sides) {
        std::cout << "Side: " << static_cast<int>(side) << " => " << capacity->getName() << std::endl;
    }
}

#pragma warning(push)
#pragma warning(disable: 4244) // Disable warning about possible data loss
const std::shared_ptr<BaseCapacity> DiceCapacity::roll(void) {
    return m_sides.find(getRandomValue(m_SIDES_COUNT))->second;
}
#pragma warning(pop)  // Restore warning settings


//const BaseCapacity& DiceCapacity::rollAdvantage(void) {
//    // TODO: Return the capacity with the highest rarity
//    return ;
//}
//
//
//const BaseCapacity& DiceCapacity::rollDisadvantage(void) {
//	// TODO: Return the capacity with the highest rarity
//    return ;
//}

