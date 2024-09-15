#include "Character.hpp"

Character::Character() : _name("Unnamed"), head(NULL)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
}

// Parametrized Constructor
Character::Character(std::string const & name) : _name(name), head(NULL)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
}

Character::Character(const Character &copy) : _name(copy._name), head(NULL)
{
    for (int i = 0; i < 4; ++i)
    {
        if (copy.inventory[i])
            inventory[i] = copy.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    // Deep copy of the linked list
    LostItems* temp = copy.head;
    while (temp)
    {
        head = insert(head, temp->addr->clone());
        temp = temp->next;
    }
}

Character& Character::operator=(const Character& src)
{
    if (this != &src)
    {
        _name = src._name;
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            inventory[i] = src.inventory[i] ? src.inventory[i]->clone() : NULL;
        }
        // Clear the existing linked list before copying
        deleteList(head);
        head = NULL;
        LostItems* temp = src.head;
        while (temp)
        {
            head = insert(head, temp->addr->clone());
            temp = temp->next;
        }
    }
    return *this;
}

// Destructor to clean up inventory and linked list
Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
    deleteList(head); // Clean up linked list
}

// Getter for character name
std::string const & Character::get_name() const{ return _name; }

// Equip Materia into the first available slot
void Character::equip(AMateria* m) 
{
    for (int i = 0; i < 4; ++i) 
    {
        if (!inventory[i]) 
        {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        head = insert(head, inventory[idx]); // Add to linked list
        inventory[idx] = NULL; 
    }
}

// Use Materia in the inventory
void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}

// Create a new LostItems for a lost Materia
LostItems* Character::create(AMateria *m)
{
    LostItems* newLostItems = new LostItems();
    newLostItems->addr = m;
    newLostItems->next = NULL;
    return newLostItems;
}

// Insert a new LostItems into the linked list
LostItems* Character::insert(LostItems *head, AMateria *m) 
{
    LostItems* newLostItems = create(m);
    newLostItems->next = head; 
    return newLostItems;
}

// Delete the entire linked list
void Character::deleteList(LostItems *head)
{
    while (head)
    {
        LostItems* temp = head;
        head = head->next;
        delete temp->addr; // Free the AMateria stored in the LostItems
        delete temp; 
    }
}
