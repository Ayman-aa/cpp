#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
			inventory[i] = NULL;
	head = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; i++)
			inventory[i] = NULL;
	head = NULL;
}

Character::Character(const Character& copy)
{
   *this = copy;
}

Character &Character::operator=(const Character& copy)
{
	if (this == &copy)
		return (*this);
	_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;;
		}
		if (copy.inventory[i])
			inventory[i] = copy.inventory[i]->clone();
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
	deleteList(head);
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = materia->clone();
			break;
		}
	}
	if (!head)
		head = create(materia);
	else
		insert(head ,materia);
}

void Character::unequip(int idx)
{
	if ((idx >= 0 && idx <= 3) && inventory[idx] != NULL)
	{
		if (!head)
			head = create(inventory[idx]);
		else
			insert(head ,inventory[idx]);
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	ICharacter *test = &target;
	if (!test)
		return;
	if ((idx >= 0 && idx <= 3) && inventory[idx] != NULL)
		inventory[idx]->use(target);
}

LostItems *Character::create (AMateria *materia)
{
	LostItems *lostItem = new LostItems;
    lostItem->addr = materia;
    lostItem->next = NULL;
    return lostItem;
}

LostItems *Character::insert (LostItems *head, AMateria *materia)
{
    LostItems *lostItem;
	
    lostItem = head;
	while (lostItem)
	{
		if (lostItem->addr == materia)
			return (head);
		lostItem = lostItem->next;
	}
	
    lostItem = head;
    while(lostItem->next != NULL)
        lostItem = lostItem->next;
    lostItem->next = create(materia);
	
    return head;
}

void Character::deleteList (LostItems *head)
{
	LostItems *tmp;

	while(head)
	{
		tmp = head;
		head = head->next;
		delete tmp->addr;
		delete tmp;
	}
}