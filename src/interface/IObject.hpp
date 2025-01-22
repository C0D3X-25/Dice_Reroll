#pragma once
#include "tool_lib.hpp"
#include <iostream>

namespace dice {

	struct Object {
		std::string m_name{ "N/A" };
		uint16_t m_value{ 0 };
	};


	class IObject {
	public:
		virtual void printObject(void) = 0;
	};


	class ObjectA : public IObject {
	public:
		ObjectA(void) = default;
		ObjectA(std::string name, uint16_t value)
			: m_name(name), m_value(value) {
		}

		void printObject(void) override {
			std::cout << "Name: " << m_name << " | Value: " << m_value << '\n';
		}

		std::string m_name{ "N/A" };
		uint16_t m_value{ 0 };
	};
	

	class ObjectB : public IObject {
	public:
		ObjectB(void) = default;
		ObjectB(std::string name, std::string description)
			: m_name(name), m_description(description) {
		}
		void printObject(void) override {
			std::cout << "Name: " << m_name << " | Description: " << m_description << '\n';
		}
		std::string m_name{ "N/A" };
		std::string m_description{ "N/A" };
	};

} // namespace dice

