#pragma once
#include "tool_lib.hpp"
#include "IObject.hpp"

#include <random>
#include <iostream>
#include <array>


namespace dice {
	class RollDice {
	public:
		uint16_t roll(uint16_t nbr_side) {

			uint16_t res = random(nbr_side);
			std::cout << "Roll: " << res << '\n';

			return res;
		}

		uint16_t rollAdvantage(uint16_t nbr_side) {

			uint16_t roll_1 = random(nbr_side);
			uint16_t roll_2 = random(nbr_side);

			std::cout << "Advantage -> First Roll (" << roll_1
				<< ") Second Roll (" << roll_2<< ")\n";

			if (roll_1 > roll_2) {
				return roll_1;
			}
			return roll_2;
		}

		uint16_t rollDisadvantage(uint16_t nbr_side) {

			uint16_t roll_1 = random(nbr_side);
			uint16_t roll_2 = random(nbr_side);

			std::cout << "Disadvantage -> First Roll (" << roll_1
				<< ") Second Roll (" << roll_2<< ")\n";

			if (roll_1 < roll_2) {
				return roll_1;
			}
			return roll_2;
		}

		//template<std::size_t N>
		//const IObject& roll(const std::array<IObject, N>& obj_array) {

		//	IObject& obj = obj_array[random(obj_array.size()) - 1];
		//	obj.printObject();

		//	return obj;
		//}

		template<std::size_t N>
		const std::shared_ptr<IObject>& roll(const std::array<std::shared_ptr<IObject>, N>& obj_array) {

			std::shared_ptr<IObject>& obj = obj_array[random(obj_array.size()) - 1];
			obj->printObject();

			return obj;
		}

	private:
		uint16_t random(const uint16_t max_value) {

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(1, max_value);

			return dis(gen);
		};
	};
} // namespace dice
