#include <iostream>
#include <map>
#include <vector>
#include "string.h"

using namespace std;
// Header file for room classes

class Room {
public:
    // All rooms have an id and a character pointer for descriptions
    Room(int, char *);

    // Rooms provide exits to the map with an integer that corresponds to a direction or path they
    // can take and the Room pointer to the Room that path leads to
    void setExit(int direction, Room *exit);

    // Checks the Room that the exit of another room leads to
    Room *getExit(int exit);

    // Each room has an ID it is referred to by
    int getId();

    // Returns the description of a room
    char *getD();

    // map containing the room exits and their corresponding locations
    map<int, Room *> exits;
    // description of the room
    char *description;
    // ID number of the room
    int id;
};