#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void) {
	std::cout << "=== Creating all trap types ===" << std::endl;
	ClapTrap clap("CT-01");
	ScavTrap scav("ST-01");
	FragTrap frag("FT-01");
	
	std::cout << "\n=== Testing ClapTrap ===" << std::endl;
	clap.attack("Enemy-1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	
	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	scav.attack("Enemy-2");
	scav.takeDamage(30);
	scav.guardGate();
	
	std::cout << "\n=== Testing FragTrap ===" << std::endl;
	frag.attack("Enemy-3");
	frag.takeDamage(50);
	frag.beRepaired(20);
	frag.highFivesGuys();
	
	std::cout << "\n=== Testing construction/destruction order ===" << std::endl;
	{
		FragTrap temp("FT-TEMP");
		temp.highFivesGuys();
	}
	
	std::cout << "\n=== Destruction ===" << std::endl;
	return 0;
}
