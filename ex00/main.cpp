#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap clap1("CT-01");
	ClapTrap clap2("CT-02");
	ClapTrap clap3("CT-03");
	ClapTrap clap4("CT-04");
	
	std::cout << "\n=== Testing attacks ===" << std::endl;
	clap1.attack("Target");
	clap1.attack("");
	
	
	std::cout << "\n=== Testing repair ===" << std::endl;
	clap1.beRepaired(5);
	clap1.beRepaired(0);
	clap1.beRepaired(-5);
	std::cout << "\n=== Testing damage ===" << std::endl;
	clap1.takeDamage(5);
	clap1.takeDamage(0);
	clap1.takeDamage(UINT_MAX);

	std::cout << "\n=== Testing actions on no energy ===" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "Attack " << i << ": ";
		clap2.attack("Target");
	}
	clap2.attack("Target");
	clap2.beRepaired(5);
	clap2.takeDamage(5);
	
	std::cout << "\n=== Testing actions on death ===" << std::endl;
	clap3.takeDamage(20);
	clap3.attack("Target");
	clap3.beRepaired(5);
	clap3.takeDamage(5);
	
	std::cout << "\n=== Testing actions on death and no energy ===" << std::endl;
	for (int i = 0; i < 10; i++) {
		clap4.attack("Target");
	}
	clap4.takeDamage(20);
	clap4.attack("Target");
	clap4.beRepaired(5);
	clap4.takeDamage(5);

	std::cout << "\n=== Destruction ===" << std::endl;
	return 0;
}
