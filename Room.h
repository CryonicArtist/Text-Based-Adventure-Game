#define ROOM_H

#include <string>
#include <vector>

class Room {
    public:
        Room(const std::string& name, const std::string& description);

        void addConnection(Room* room);
        void displayInfo() const;
        std::vector<Room*> getConnections() const;
        std::string getName() const;

    private:
        std::string name;
        std::string description;
        std::vector<Room*> connections;
};
