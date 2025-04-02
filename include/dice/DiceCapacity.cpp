#include "DiceCapacity.hpp"


using namespace dice;

dice::DiceCapacity::DiceCapacity(void) {
    std::fill(m_sides.begin(), m_sides.end(), m_empty);
}

DiceCapacity::DiceCapacity(const BaseCapacity& capacity) {

}


void DiceCapacity::setCapacity(const BaseCapacity& capacity) {

}


const std::shared_ptr<BaseCapacity> DiceCapacity::getCapacity(const uint8_t index) const {
    return m_sides.at(index);
}


void DiceCapacity::roll(void) {

}


void DiceCapacity::printDice(void) {

}


uint16_t DiceCapacity::rollAdvantage(void) {

    return 0;
}


uint16_t DiceCapacity::rollDisadvantage(void) {

    return 0;
}

