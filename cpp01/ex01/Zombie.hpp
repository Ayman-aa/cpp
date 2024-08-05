#ifndef ZOMBIE__HPP
# define ZOMBIE__HPP

# include <iostream>

class Zombie
{
    private:
        std::string _name;
    
    public:
        Zombie(std::string name);
        Zombie();
        ~Zombie(void);

        std::string getName(void);
        void        setName(std::string name);

        void        announce(void);
};

#endif