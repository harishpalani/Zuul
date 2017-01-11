#include "room.h"

using namespace std;

Room::Room(int _id, char *_description) {
    id = _id;
    description = _description;
}

int Room::getID() {
    return id;
}

char *Room::getDescription() {
    return description;
}

void Room::setExit(int direction, Room *exit) {
    exits[direction] = exit;
}

Room *Room::getExit(int exit) {
    map<int, Room *>::iterator it;
    it = exits.find(exit);
    
    if (it != exits.end()) {
        return exits.find(exit)->second;
    } else {
        return NULL;
    }
}