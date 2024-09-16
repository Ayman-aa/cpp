#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <cstring>

typedef struct LostItems{
    AMateria *addr;
    LostItems* next;
}LostItems;

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

        std::string const & getName() const;
        void equip(AMateria* materia);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        LostItems *create (AMateria *materia);
        LostItems * insert (LostItems *head, AMateria *materia);
        void deleteList (LostItems *head);
};

#endif