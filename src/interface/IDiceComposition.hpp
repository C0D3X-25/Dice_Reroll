#pragma once
#include "tool_lib.hpp"
#include "IObject.hpp"

#include <random>
#include <iostream>
#include <array>


namespace dice {

	struct Object;

	class IMultiRollNumeric {
	public:
		virtual uint16_t rollAdvantage(void) = 0;
		virtual uint16_t rollDisadvantage(void) = 0;
	};


	class CompDiceLogic {
	public:
		uint16_t roll(const uint16_t m_side) {

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(1, m_side);

			return dis(gen);
		};
	};


	class CompDiceNumeric : public IMultiRollNumeric, CompDiceLogic {
	public:
		CompDiceNumeric(const uint16_t side)
			: m_side(side) {
		}
		~CompDiceNumeric() = default;

		uint16_t roll(void) {

			uint16_t res = CompDiceLogic::roll(m_side);
			std::cout << "Roll: " << res << '\n';
			return CompDiceLogic::roll(m_side);
		}

		uint16_t rollAdvantage(void) override {
			uint16_t roll_1 = CompDiceLogic::roll(m_side);
			uint16_t roll_2 = CompDiceLogic::roll(m_side);

			std::cout << "Advantage    -> First Roll (" << roll_1
				<< ") Second Roll (" << roll_2 << ")\n";

			if (roll_1 > roll_2) {
				return roll_1;
			}
			return roll_2;
		}

		uint16_t rollDisadvantage(void) override {
			uint16_t roll_1 = CompDiceLogic::roll(m_side);
			uint16_t roll_2 = CompDiceLogic::roll(m_side);

			std::cout << "Disadvantage -> First Roll (" << roll_1
				<< ") Second Roll (" << roll_2 << ")\n";

			if (roll_1 < roll_2) {
				return roll_1;
			}
			return roll_2;
		}

	private:
		uint16_t m_side{ 0 };
	};


	template <std::size_t N>
	class CompDiceObject : public CompDiceLogic {
	public:
		CompDiceObject(const std::array<Object, N>& obj_array)
			: m_objects(obj_array) {
		}
		~CompDiceObject() = default;

		const Object& roll(void) {

			Object res = m_objects[CompDiceLogic::roll(m_objects.size()) - 1];
			std::cout << "Name: " << res.m_name << " | Value: " << res.m_value << '\n';

			return m_objects[CompDiceLogic::roll(m_objects.size()) - 1];;
		}

	private:
		std::array<Object, N> m_objects;
	};

} // namespace dice