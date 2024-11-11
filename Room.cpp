#include "Room.h"
#include <iostream>

Room::Room(const std::string& name, const std::string& description)
    : name(name), description(description){}

    void Room::addConnection(Room* room){
        connections.push_back(room);
    }

    void Room::displayInfo() const{
        std::cout << "You are in " << name << ".\n" << description << ".\n";
    }

    std::vector<Room*> Room::getConnections() const{
        return connections;
    }

    std::string Room::getName() const{
        return name;
    }