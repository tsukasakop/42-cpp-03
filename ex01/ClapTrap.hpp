#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <climits>

class ClapTrap {
	const static unsigned int maxHitPoints = UINT_MAX;

protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap(void);
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
