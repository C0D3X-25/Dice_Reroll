#include "DiceCapacity.hpp"


using namespace dice;

dice::DiceCapacity::DiceCapacity(void) {
	// Initialize the sides of the dice with a nothing capacity
	std::shared_ptr<BaseCapacity> nothing_capacity = std::make_shared<CapacityNothing>();

    for (uint8_t i = 1; i <= m_SIDES_COUNT; ++i) {
        m_sides[i] = nothing_capacity;
    }
}


void DiceCapacity::setCapacity(const std::shared_ptr<BaseCapacity> sp_capacity, const uint8_t side) {
    auto it = m_sides.find(side);
    if (it != m_sides.end()) {
        it->second = sp_capacity;
    }
}


const std::shared_ptr<BaseCapacity> DiceCapacity::getCapacity(const uint8_t side) const {
    auto it = m_sides.find(side);
    if (it != m_sides.end()) {
        return it->second;
    }
    return nullptr;
}


//#pragma warning(push)
//#pragma warning(disable: 4244) // Disable warning about possible data loss
//const BaseCapacity& DiceCapacity::roll(void) {
//    return m_sides.find(generateRandomValue(m_SIDES_COUNT))->second;
//}
//#pragma warning(pop)  // Restore warning settings


void DiceCapacity::printDiceSides(void) {
    for (const auto& [side, capacity] : m_sides) {
        std::cout << "Side: " << static_cast<int>(side) << '\n';
        if (capacity) {
            capacity->printCapacity();
        }
    }
}

#pragma warning(push)
#pragma warning(disable: 4244) // Disable warning about possible data loss
const BaseCapacity& DiceCapacity::roll(void) {
    auto it = m_sides.find(getRandomValue(m_SIDES_COUNT));
    if (it != m_sides.end() && it->second) {
        return *it->second;
    }
    static CapacityNothing default_capacity;
    return default_capacity;
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

