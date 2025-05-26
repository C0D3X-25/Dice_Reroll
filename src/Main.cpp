/*****************************************************************//**
 * @file   Main.cpp
 * @brief  Entry point of the app
 * 
 * @author codex
 * @date   January 2025
 *********************************************************************/
#pragma once

#include "capacity/CapacityPlayerSingleAttack.hpp"
#include "capacity/CapacityLibrary.hpp"
#include "dice/DiceCapacity.hpp"

#include "entity/PlayerEntityGenerator.hpp"
#include "group/Team.hpp"

#include <iostream>
#include <array>
#include <memory>


int main() {

	using namespace dice;
	using namespace entity;
	using namespace capacity;
	using namespace group;
	
	CapacityLibrary capacity_book;
	
	PlayerEntityGenerator entity_generator;
	BasePlayerEntity entity_1 = entity_generator.generateNewPlayerEntity();
	BasePlayerEntity entity_2 = entity_generator.generateNewPlayerEntity();
	BasePlayerEntity entity_3 = entity_generator.generateNewPlayerEntity();
	BasePlayerEntity entity_4 = entity_generator.generateNewPlayerEntity();
	BasePlayerEntity entity_5 = entity_generator.generateNewPlayerEntity();
	BasePlayerEntity entity_6 = entity_generator.generateNewPlayerEntity();
	entity_6.setCapacity(capacity_book.attackRandom(entity_6), 3);

	Team team_1("Team 1");
	team_1.addEntity(std::make_unique<BasePlayerEntity>(entity_1), 0);
	team_1.addEntity(std::make_unique<BasePlayerEntity>(entity_2), 0);
	team_1.addEntity(std::make_unique<BasePlayerEntity>(entity_3), 0);
	team_1.addEntity(std::make_unique<BasePlayerEntity>(entity_4), 0);

	Team team_2("Team 2");
	team_2.addEntity(std::make_unique<BasePlayerEntity>(entity_5), 0);
	team_1.transferEntityTo(team_2, 1, 0);
	team_2.addEntity(std::make_unique<BasePlayerEntity>(entity_6), 0);

	team_1.printGroup();
	team_2.printGroup();

	//entity_1.printEntity();
	//std::cout << "========================================================\n\n";
	//entity_2.printEntity();
	//std::cout << "========================================================\n\n";




	//for (size_t i = 0; i < 20; i++) {
	//	BaseCapacity cap = entity_1.rollDiceCapacity();
	//	std::cout << "Roll No " << i + 1 << ": "  << cap.getCapacityName() << '\n';
	//}
}

