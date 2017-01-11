#include "room.h"

using namespace std;


// Room class for all rooms that will be used. Inherits a header file.

Room::Room(int _id, char *_description) {
    // Each room has an individual id and description
    id = _id;
    description = _description;
}

int Room::getId() {
    // returns the room id as an int
    return id;
}

char *Room::getD() {
    // returns the room id as a character pointer
    return description;
}

void Room::setExit(int direction, Room *nExit) {
    // connects the exit path and the location together in the map
    exits[direction] = nExit;
}

Room *Room::getExit(int exit) {
    // Creates an iterator for the map that finds the room associated with the exit number
    map<int, Room *>::iterator it;
    it = exits.find(exit);
    if (it != exits.end()) {
        return exits.find(exit)->second;
    } else {
        return NULL;
    }
}