#pragma once
#include "tool_lib.hpp"

#include <random>
#include <iostream>
#include <vector>

namespace dice {

	struct Object {
		std::string name;
		uint16_t value;
	};

	class DiceNumeric {
	public:
		DiceNumeric(const uint16_t side)
		: m_side(side) 
		{

		}
		~DiceNumeric() = default;

		uint16_t getNbrSide() const {
			return m_side;
		}

	private:
		uint16_t m_side = 0;
	};

    class DiceObject {
    public:
        DiceObject(const std::vector<Object>& obj_vector)
            : m_object(obj_vector)
        {

        }
        ~DiceObject() = default;

        const Object& getObject(const uint16_t index) const {
            return m_object[index];
        }

		uint16_t getNbrSide() const {
			return m_object.size();
		}

    private:
		std::vector<Object> m_object;
    };


	class RollDiceFactory {
	public:

		RollDiceFactory() = default;
		~RollDiceFactory() = default;

		uint16_t roll(const DiceNumeric& dice_num) {

			//return rollLogic(dice_num.getNbrSide());
			
			uint16_t res = rollLogic(dice_num.getNbrSide());
			std::cout << "Roll: " << res << '\n';
			return res;
		}

		uint16_t rollAdvantage(const DiceNumeric& dice_num) {

			uint16_t first_roll = rollLogic(dice_num.getNbrSide());
			uint16_t second_roll = rollLogic(dice_num.getNbrSide());

			std::cout << "Advantage -> First Roll (" << first_roll
				<< ") Second Roll (" << second_roll << ")\n";

			if (first_roll > second_roll) {
				return first_roll;
			}
			return second_roll;
		}

		uint16_t rollDisadvantage(const DiceNumeric& dice_num) {
			uint16_t first_roll = rollLogic(dice_num.getNbrSide());
			uint16_t second_roll = rollLogic(dice_num.getNbrSide());

			std::cout << "Disadvantage -> First Roll (" << first_roll 
				<< ") Second Roll (" << second_roll << ")\n";

			if (first_roll < second_roll) {
				return first_roll;
			}
			return second_roll;
		}

		const Object& roll(const DiceObject& dice_obj) const {

			//return dice_obj.getObject(rollLogic(dice_obj.getNbrSide()) - 1);
			
			Object res = dice_obj.getObject(rollLogic(dice_obj.getNbrSide()) - 1);
			std::cout << "Name: " << res.name << " | Value: " << res.value << '\n';
			
			return res;
		}

	private:

		// Return a random number
		uint16_t rollLogic(const uint16_t side) const {

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> distrib(1, side);

			return distrib(gen);
		}
	};



} // namespace dice
