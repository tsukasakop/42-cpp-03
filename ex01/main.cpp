#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	std::cout << "=== Creating ClapTrap and ScavTrap ===" << std::endl;
	ClapTrap clap("CT-01");
	ScavTrap scav("ST-01");
	
	std::cout << "\n=== Testing ClapTrap ===" << std::endl;
	clap.attack("Enemy-1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	
	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	scav.attack("Enemy-2");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	
	std::cout << "\n=== Testing construction/destruction order ===" << std::endl;
	{
		ScavTrap temp("ST-TEMP");
		temp.guardGate();
	}
	
	std::cout << "\n=== Destruction ===" << std::endl;
	return 0;
}
