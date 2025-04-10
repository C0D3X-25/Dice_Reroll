#pragma once

#include <random>
#include <iostream>

/// @file ADice.hpp
/// @brief Defines abstract base class template for dice implementations
/// @details Provides core functionality for different types of dice including 
/// random number generation and virtual interface for rolling and display

/// Methods MUST be defined in the .hpp, because of the template<T>, Type need to be know at compile time !!

namespace dice {

    /// @brief Abstract base class template for dice implementations
    /// @tparam T The return type for dice roll results
    template <typename T>
    class ADice {
    public:
        virtual ~ADice(void) = default;

        /// @brief Pure virtual method to roll the dice
        /// @return Result of the dice roll as type T
        virtual const T roll(void) = 0;

        /// @brief Pure virtual method to display dice information
        virtual void printDice(void) = 0;

    protected:
        /// @brief Helper method to generate random numbers within a range
        /// @param max_value Maximum value (inclusive) for random number generation
        /// @param min_value Minimum value (inclusive) for random number generation, defaults to 1
        /// @return Random number between min_value and max_value
        uint16_t getRandomValue(const uint16_t max_value, const uint16_t min_value = 1) {
            std::random_device getRandomValue;
            std::mt19937 generate(getRandomValue());
            std::uniform_int_distribution<> distribution(min_value, max_value);

            return distribution(generate);
        };
    };
}