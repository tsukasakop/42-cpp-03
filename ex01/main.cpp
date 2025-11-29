#include "ScavTrap.hpp"
#include <iostream>
#include <iomanip>

int main(void) {
	{
		std::cout << "\n=== CASE0: Testing constructor/destructor ===" << std::endl;
		{
			std::cout << "\n-- Default constructor --" << std::endl;
			ScavTrap defaultTrap;
		}
		{
			std::cout << "\n-- Parameterized constructor --" << std::endl;
			ScavTrap trap("CASE0");
		}
		{
			std::cout << "\n-- Copy constructor --" << std::endl;
			ScavTrap trap("CASE0-COPY");
			{
				ScavTrap copyTrap(trap);
			}
		}
		{
			std::cout << "\n-- Copy assignment operator --" << std::endl;
			ScavTrap trap("CASE0-ASSIGN");
			{
				ScavTrap copyTrap("CASE0-DUMMY");
				copyTrap = trap;
			}
		}
	}
	{
		// Arrange
		std::cout.setstate(std::ios_base::failbit);
		ScavTrap trap("CASE1");

		// Act
		std::cout.clear();
		std::cout << "\n=== CASE1: Testing standard actions available ===" << std::endl;
		trap.guardGate();
		trap.attack("Target");
		trap.attack("");
		trap.beRepaired(5);
		trap.beRepaired(0);
		trap.beRepaired(UINT_MAX);
		trap.takeDamage(5);
		trap.takeDamage(0);
		trap.takeDamage(UINT_MAX);
		std::cout.setstate(std::ios_base::failbit);
	}
	{
		// Arrange
		ScavTrap trap("CASE2");
		for (int i = 0; i < 50; i++) {
			std::cout << "Attack " << std::setw(2) << i << ": ";
			trap.attack("Target");
		}

		// Act
		std::cout.clear();
		std::cout << "\n=== CASE2: Testing actions on no energy ===" << std::endl;
		trap.guardGate();
		trap.attack("Target");
		trap.beRepaired(5);
		trap.takeDamage(5);
		std::cout.setstate(std::ios_base::failbit);
	}	
	{
		// Arrange
		ScavTrap trap("CASE3");
		trap.takeDamage(UINT_MAX);

		// Act
		std::cout.clear();
		std::cout << "\n=== CASE3: Testing actions on death ===" << std::endl;
		trap.guardGate();
		trap.attack("Target");
		trap.beRepaired(5);
		trap.takeDamage(5);
		std::cout.setstate(std::ios_base::failbit);
	}
	{

		// Arrange
		ScavTrap trap("CASE4");
		for (int i = 0; i < 50; i++) {
			std::cout << "Attack " << std::setw(2) << i << ": ";
			trap.attack("Target");
		}
		trap.takeDamage(UINT_MAX);

		// Act
		std::cout.clear();
		std::cout << "\n=== CASE4: Testing actions on death and no energy ===" << std::endl;
		trap.guardGate();
		trap.attack("Target");
		trap.beRepaired(5);
		trap.takeDamage(5);
		std::cout.setstate(std::ios_base::failbit);
	}
	return 0;
}
