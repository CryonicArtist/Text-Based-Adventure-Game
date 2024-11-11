#include "Room.h"
#include <iostream>
#include <string>

int main(){
    //create room
    Room entrance("Entrance Hall", "A grand entrance with marble floors and a large chandelier.");
    Room libary("Libary", "Shelves of old books line the walls. It smells of aged paper and dust. ");
    Room garden("Garden", "A lush garden filled with the scent of flowers and the sound of birds.");
    Room secretChamber("Secret Chamber", "A dimly lit room with mysterious symbols on the walls.");
    Room fountain("Fountain", "A grand fountain with roses all around.");


    // Connect rooms
    entrance.addConnection(&libary);
    entrance.addConnection(&garden);
    libary.addConnection(&secretChamber);
    garden.addConnection(&fountain);

    //gameplay loop
    Room* currentRoom = &entrance;
    bool playing = true;
    while (playing){
        currentRoom->displayInfo();
        std::vector<Room*> connections = currentRoom->getConnections();

        //display choices
        if (connections.empty()){
            std::cout << "There are no exits. The game ends here.\n";
        }

        std::cout << "Available exits:\n";
        for(size_t i = 0; i < connections.size(); i++){
            std::cout << i + 1 << ". " << connections[i]->getName() << "\n";
        }

        //Get user input
        std::cout << "Choose an exit (number) or 0 to quit: ";
        int choice;
        std::cin >> choice; 

        if(choice == 0){
            playing = false;
        }
        else if (choice > 0 && choice <= static_cast<int>(connections.size())){
            currentRoom = connections[choice - 1];
        } else{
            std::cout << "Invalid choice. Try again .\n";
        }
    }

    std::cout << "Thanks for playing!\n";
    return 0;

}