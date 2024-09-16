#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    // Create a new character "Player"
    std::cout << "Creating Player character...\n";
    Character* player = new Character("Player");

    // Create Materias
    std::cout << "Creating Ice and Cure Materias...\n";
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    // Equip Materias
    std::cout << "Equipping Ice and Cure to Player...\n";
    player->equip(ice);
    player->equip(cure);

    // Create a target character "Dummy"
    std::cout << "Creating Dummy character...\n";
    Character* dummy = new Character("Dummy");

    // Use Materias on Dummy
    std::cout << "Using Ice on Dummy...\n";
    player->use(0, *dummy); // Should shoot an ice bolt at Dummy
    std::cout << "Using Cure on Dummy...\n";
    player->use(1, *dummy); // Should heal Dummy's wounds

    // Unequip the first Materia (Ice)
    std::cout << "Unequipping Ice from Player...\n";
    player->unequip(0); // This should add Ice to the lost items list

    // Unequip the second Materia (Cure)
    std::cout << "Unequipping Cure from Player...\n";
    player->unequip(1); // This should add Cure to the lost items list

    // Equip new Materia in the emptied slots
    std::cout << "Re-equipping Ice and Cure Materias to Player...\n";
    AMateria* ice2 = new Ice(); // Creating new Ice Materia
    AMateria* cure2 = new Cure(); // Creating new Cure Materia
    player->equip(ice2);
    player->equip(cure2);
    player->equip(ice); // Re-equipping the lost Ice Materia
    player->equip(cure); // Re-equipping the lost Cure Materia
    player->use(2, *dummy); // Using Ice on Dummy

    // Deep copy test (copy constructor)
    std::cout << "Creating a deep copy of Player character (copy constructor)...\n";
    Character* playerCopy = new Character(*player); // Deep copy of player

    // Use Materias in the copied character to verify deep copy
    std::cout << "Using Materias on the copied Player...\n";
    playerCopy->use(0, *dummy); // Using Ice2 on Dummy
    playerCopy->use(1, *dummy); // Using Cure2 on Dummy

    // Deep copy test (assignment operator)
    std::cout << "Testing assignment operator for deep copy...\n";
    Character anotherPlayer("AnotherPlayer");
    anotherPlayer = *player; // Assigning the player to anotherPlayer

    // Use Materias in anotherPlayer to verify deep copy
    std::cout << "Using Materias on AnotherPlayer...\n";
    anotherPlayer.use(0, *dummy); // Using Ice2 on Dummy
    anotherPlayer.use(1, *dummy); // Using Cure2 on Dummy

    // Destructor test and cleanup
    std::cout << "Deleting Player, Dummy, PlayerCopy, and AnotherPlayer...\n";
    delete dummy;
    delete playerCopy;
    delete player;
    std::cout << "All objects successfully deleted.\n";
    return 0;
}