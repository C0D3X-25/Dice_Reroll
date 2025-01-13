/*****************************************************************//**
 * @file   Main.cpp
 * @brief  Entry point of the app
 * 
 * @author codex
 * @date   January 2025
 *********************************************************************/

#include "tool_lib.hpp"
#include "interface/IDiceFactory.hpp"


#include <iostream>
#include <vector>

using namespace dice;
int main() {

	std::vector<Object> obj = {
		{"Sword", 10},
		{"Shield", 5},
		{"Potion", 15}
	};
	
	DiceObject dice_obj(obj);
	DiceNumeric dice_num(10);

	RollDiceFactory factory;
	for (int i = 0; i < 10; i++) {
		factory.roll(dice_obj);
		factory.roll(dice_num);
		factory.rollAdvantage(dice_num);
		factory.rollDisadvantage(dice_num);
	}

	RollDiceFactory* p_factory = new RollDiceFactory();
	for (int i = 0; i < 10; i++) {
		p_factory->roll(dice_obj);
		p_factory->roll(dice_num);
		p_factory->rollAdvantage(dice_num);
		p_factory->rollDisadvantage(dice_num);
	}

    tool::drawLibraryFunctionsHelper();
}

