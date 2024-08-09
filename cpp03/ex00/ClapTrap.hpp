#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;

    public:
        ClapTrap(void);                                // Default constructor
        ClapTrap(const ClapTrap& other);           // Copy constructor
        ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
        ~ClapTrap();                               // Destructor

        // Parameterized constructor
        ClapTrap(std::string name);

        void attack(const std::string& target);
        void takeDamage(int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
        void setAttackDamage(int attackDamage);
};

#endif