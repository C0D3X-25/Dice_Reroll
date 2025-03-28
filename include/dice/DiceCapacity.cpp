#include "DiceCapacity.hpp"


using namespace dice;

DiceCapacity::DiceCapacity(const ACapacity& capacity) {

}


void DiceCapacity::setCapacity(const ACapacity& capacity) {
}


ACapacity DiceCapacity::getCapacity(const uint8_t index) const {
    return m_sides[0];
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

