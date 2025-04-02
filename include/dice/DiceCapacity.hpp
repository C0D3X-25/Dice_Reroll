#pragma once
#include "ADice.hpp"
#include "IRollAdvantageDisadvantage.hpp"
#include "../capacity/BaseCapacity.hpp"
#include "../capacity/CapacityNothing.hpp"

#include <array>
#include <map>
#include <memory>

namespace capacity {
    class BaseCapacity;
    class CapacityNothing;
}

namespace dice {

    using capacity::BaseCapacity;
    using capacity::CapacityNothing;

    /**
     * @brief A specialized dice that contains capacity effects on each side
     * 
     * This class represents a 10-sided dice where each side can be assigned
     * a specific capacity effect (derived from BaseCapacity). When rolled,
     * it returns the capacity effect of the rolled side.
     * 
     * Inherits from ADice for basic dice functionality and IRollAdvantageDisadvantage
     * for advantage/disadvantage roll mechanics.
     */
    class DiceCapacity: 
        ADice<std::shared_ptr<BaseCapacity>>, 
        IRollAdvantageDisadvantage<std::shared_ptr<BaseCapacity>> {

    public:
        /**
         * @brief Default constructor
         * Initializes an empty dice with no capacities assigned
         */
        DiceCapacity(void);
        ~DiceCapacity(void) = default;

        /**
         * @brief Assigns a capacity to a specific side of the dice
         * @param capacity The capacity to assign
         * @param side The side number to assign the capacity to (1-10)
         */
        void setCapacity(const std::shared_ptr<BaseCapacity> capacity, const uint8_t side);
        
        /**
         * @brief Retrieves the capacity assigned to a specific side
         * @param side The side number to get the capacity from (1-10)
         * @return The capacity assigned to the specified side
         */
        const std::shared_ptr<BaseCapacity> getCapacity(const uint8_t side) const;

        /**
         * @brief Performs an advantage roll (rolls twice and takes the better result)
         * @return The capacity from the higher roll
         */
        const std::shared_ptr<BaseCapacity> rollAdvantage(void) override;
        
        /**
         * @brief Performs a disadvantage roll (rolls twice and takes the worse result)
         * @return The capacity from the lower roll
         */
        const std::shared_ptr<BaseCapacity> rollDisadvantage(void) override;

        /**
         * @brief Performs a single roll of the dice
         * @return The capacity from the rolled side
         */
        const std::shared_ptr<BaseCapacity> roll(void) override;
        
        /**
         * @brief Prints the current state of the dice
         */
        void printDice(void) override;

        /** @brief Number of sides on the dice */
        static constexpr uint8_t m_SIDES_COUNT = 10;

    private:
        /** @brief Map storing the capacity for each side of the dice */
        std::map<uint8_t, std::shared_ptr<BaseCapacity>> m_sides{};
    };
}