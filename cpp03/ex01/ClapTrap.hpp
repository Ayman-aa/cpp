#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    protected:
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

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
        void setAttackDamage(int attackDamage);
        int getAttackDamage(void) const;
};

#endif