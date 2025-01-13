/*****************************************************************//**
 * @file   Main.cpp
 * @brief  Entry point of the app
 * 
 * @author codex
 * @date   January 2025
 *********************************************************************/
#pragma once
#include "tool_lib.hpp"
#include "interface/IDiceFactory.hpp"
#include "interface/IDiceComposition.hpp"
#include "interface/IObject.hpp"


#include <iostream>
#include <array>

using namespace dice;
int main() {
	Object nothing = { "Empty", 0 };
	Object weapon = { "Sword", 10 };
	Object shield = { "Shield", 5 };
	Object potion = { "Potion", 15 };

	std::array<Object, 10> obj_array;
	obj_array.fill(nothing);
	obj_array = {
		weapon,
		shield,
		potion
	};

	DiceObject dice_obj(obj_array);
	DiceNumeric dice_num(10);

	RollDiceFactory factory;
	for (int i = 0; i < 10; i++) {
		factory.roll(dice_obj);
		factory.roll(dice_num);
		factory.rollAdvantage(dice_num);
		factory.rollDisadvantage(dice_num);
	}
	std::cout << "----------------------\n\n";

	RollDiceFactory* p_factory = new RollDiceFactory();
	for (int i = 0; i < 10; i++) {
		p_factory->roll(dice_obj);
		p_factory->roll(dice_num);
		p_factory->rollAdvantage(dice_num);
		p_factory->rollDisadvantage(dice_num);
	}
	delete p_factory;
	std::cout << "======================\n\n";


	CompDiceObject comp_dice_obj(obj_array);
	CompDiceNumeric comp_dice_num(10);
	for (int i = 0; i < 10; i++) {
		comp_dice_obj.roll();
		comp_dice_num.roll();
		comp_dice_num.rollAdvantage();
		comp_dice_num.rollDisadvantage();
	}
	std::cout << "======================\n\n";



    //tool::drawLibraryFunctionsHelper();
}

