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
//#include "interface/Dice.hpp"
#include "interface/IObject.hpp"

#include "../include/entity/PlayerEntityWarrior.hpp"
#include "../include/capacity/CapacityAttack.hpp"


#include <iostream>
#include <array>

using namespace dice;
using namespace entity;
using namespace capacity;

int main() {
	
	PlayerEntityWarrior 
		entity_1("Entity 1", 20, 5),
		entity_2("Entity 2", 30, 10);

	entity_1.printEntity();
	entity_2.printEntity();

	//CapacityPlayerSingleAttack attack;

	//entity_1.useCapacity(attack, entity_2);
	//entity_1.useCapacity(attack, entity_2);
	//entity_1.useCapacity(attack, entity_2);



	//Object nothing = { "Empty", 0 };
	//Object weapon = { "Sword", 10 };
	//Object shield = { "Shield", 5 };
	//Object potion = { "Potion", 15 };

	//std::array<Object, 10> obj_array;
	//obj_array.fill(nothing);
	//obj_array = {
	//	weapon,
	//	shield,
	//	potion
	//};

	//ObjectA nothing_c = { "Empty", 0 };
	//ObjectA weapon_c = { "Sword", 10 };
	//ObjectA shield_c = { "Shield", 5 };
	//ObjectA potion_c = { "Potion", 15 };

	//ObjectB nothing_b = { "Empty", "N/A" };
	//ObjectB weapon_b = { "Sword", "A sword is a bladed melee weapon." };
	//ObjectB shield_b = { "Shield", "A shield is a piece of personal armour." };
	//ObjectB potion_b = { "Potion", "A potion is a magic liquid." };

	//std::array<std::shared_ptr<IObject>, 10> c_obj_array;
	//c_obj_array.fill(std::make_shared<ObjectA>(nothing_c));
	//c_obj_array = {
	//	std::make_shared<ObjectA>(weapon_c),
	//	std::make_shared<ObjectA>(shield_c),
	//	std::make_shared<ObjectA>(potion_c)
	//};

	//DiceObject dice_obj(obj_array);
	//DiceNumeric dice_num(10);

	//RollDiceFactory factory;
	//for (int i = 0; i < 10; i++) {
	//	factory.roll(dice_obj);
	//	factory.roll(dice_num);
	//	factory.rollAdvantage(dice_num);
	//	factory.rollDisadvantage(dice_num);
	//}
	//std::cout << "----------------------\n\n";

	//RollDiceFactory* p_factory = new RollDiceFactory();
	//for (int i = 0; i < 10; i++) {
	//	p_factory->roll(dice_obj);
	//	p_factory->roll(dice_num);
	//	p_factory->rollAdvantage(dice_num);
	//	p_factory->rollDisadvantage(dice_num);
	//}
	//delete p_factory;
	//std::cout << "======================\n\n";


	//CompDiceObject comp_dice_obj(obj_array);
	//CompDiceNumeric comp_dice_num(10);
	//for (int i = 0; i < 10; i++) {
	//	comp_dice_obj.roll();
	//	comp_dice_num.roll();
	//	comp_dice_num.rollAdvantage();
	//	comp_dice_num.rollDisadvantage();
	//}
	//std::cout << "======================\n\n";

	//RollDice roll_dice;
	//for (int i = 0; i < 10; i++) {
	//	roll_dice.roll(10);
	//	roll_dice.roll(c_obj_array);
	//}

    //tool::drawLibraryFunctionsHelper();
}

