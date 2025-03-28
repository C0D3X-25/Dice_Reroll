#pragma once

#include <random>
#include <iostream>

namespace dice{
	class ADice {
	public:
		virtual ~ADice(void) = default;


		virtual void roll(void) = 0;
		virtual void printDice(void) = 0;

	private:
		uint16_t random(const uint16_t max_value) {

			std::random_device random;
			std::mt19937 generate(random());
			std::uniform_int_distribution<> distribution(1, max_value);

			return distribution(generate);
		};
	};
}
