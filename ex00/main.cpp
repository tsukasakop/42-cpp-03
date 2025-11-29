#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap clap1("CT-01");
	ClapTrap clap2("CT-02");
	
	std::cout << "\n=== Testing attacks ===" << std::endl;
	clap1.attack("Enemy-1");
	clap2.attack("Enemy-2");
	
	std::cout << "\n=== Testing damage ===" << std::endl;
	clap1.takeDamage(5);
	clap1.takeDamage(3);
	
	std::cout << "\n=== Testing repair ===" << std::endl;
	clap1.beRepaired(4);
	
	std::cout << "\n=== Testing energy depletion ===" << std::endl;
	for (int i = 0; i < 10; i++) {
		clap2.attack("Target");
	}
	clap2.attack("Target");  // エネルギー切れ
	
	std::cout << "\n=== Testing death ===" << std::endl;
	clap1.takeDamage(20);
	clap1.attack("Target");  // 死亡後の攻撃
	clap1.beRepaired(5);      // 死亡後の修理
	
	std::cout << "\n=== Destruction ===" << std::endl;
	return 0;
}
