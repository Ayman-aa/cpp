#ifndef ZOMBIE__HPP
# define ZOMBIE__HPP

# include <iostream>

class Zombie
{
    private:
        std::string _name;
    
    public:
        Zombie(std::string name);
        ~Zombie(void);
        void        announce(void);
};

#endif