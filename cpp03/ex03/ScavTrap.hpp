#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();                                
        ScavTrap(const ScavTrap& other);           
        ScavTrap& operator=(const ScavTrap& other); 
        ~ScavTrap();                               

        ScavTrap(const std::string& name);

        void attack(const std::string& target);
        void guardGate();
};

#endif