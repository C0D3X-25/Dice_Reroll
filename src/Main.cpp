/*****************************************************************//**
 * @file   Main.cpp
 * @brief  Entry point of the app
 * 
 * @author codex
 * @date   January 2025
 *********************************************************************/
#pragma once

#include "capacity/CapacityPlayerSingleAttack.hpp"
#include "dice/DiceCapacity.hpp"

#include "entity/GeneratePlayerEntity.hpp"
#include "group/Team.hpp"

#include <iostream>
#include <array>
#include <memory>


int main() {

	using namespace dice;
	using namespace entity;
	using namespace capacity;
	using namespace group;
	
	
	GeneratePlayerEntity entity_generator;
	std::unique_ptr<BasePlayerEntity> entity_1 = entity_generator.generateNewPlayerEntity();
	std::unique_ptr<BasePlayerEntity> entity_2 = entity_generator.generateNewPlayerEntity();

	Team team_1;
    team_1.addEntity(std::unique_ptr<BaseEntity>(std::move(entity_1)), 0);
	team_1.addEntity(std::move(entity_2), 0);

	std::cout << team_1.getGroupSize() << '\n';

	team_1.printTeam();

	//entity_1->printEntity();
	//std::cout << "========================================================\n\n";
	//entity_2->printEntity();
	//std::cout << "========================================================\n\n";




	//for (size_t i = 0; i < 20; i++) {
	//	BaseCapacity cap = entity_1.rollDiceCapacity();
	//	std::cout << "Roll No " << i + 1 << ": "  << cap.getCapacityName() << '\n';
	//}
}

