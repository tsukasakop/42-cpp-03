#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
		return;
	}
	
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target 
	          << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return;
	}
	
	if (amount >= this->hitPoints) {
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " takes " << amount 
		          << " damage and is destroyed!" << std::endl;
	} else {
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount 
		          << " damage! (" << this->hitPoints << " HP left)" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " is dead and cannot be repaired!" << std::endl;
		return;
	}
	if (this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
		return;
	}
	
	unsigned int amountToRepair = amount;
	if (amount > maxHitPoints || maxHitPoints - amount < this->hitPoints) {
		std::cerr << "[WARN] ClapTrap: beRepaired: called with too large repair amount, setting hit points to maximum! (=" << maxHitPoints << ")" << std::endl;
		amountToRepair = maxHitPoints - this->hitPoints;
	}
	this->energyPoints--;
	this->hitPoints += amountToRepair;
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount 
	          << " hit points! (" << this->hitPoints << " HP now)" << std::endl;
}
