#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <cstring>

typedef struct LostItems{
    AMateria *addr;
    LostItems* next;
};

class Character : public ICharacter
{
    private :
    
        std::string _name;
        AMateria *inventory[4];
        LostItems *head;

    public:

        Character();
        Character(std::string const & name);
        Character(const Character &copy);
        Character &operator=(const Character& src);
        ~Character();

        std::string const & get_name() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        LostItems *create (AMateria *m);
        LostItems * insert (LostItems *head, AMateria *m);
        void deleteList (LostItems *head);
};

#endif