#pragma once

#include <random>
#include <iostream>

namespace dice{
	template <typename T>
	class ADice {
	public:
		virtual ~ADice(void) = default;

		virtual const T roll(void) = 0;
		virtual void printDice(void) = 0;

	protected:
		uint16_t getRandomInteger(const uint16_t max_value) {

			std::random_device getRandomInteger;
			std::mt19937 generate(getRandomInteger());
			std::uniform_int_distribution<> distribution(1, max_value);

			return distribution(generate);
		};
	};
}
