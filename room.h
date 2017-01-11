#include <iostream>
#include <map>
#include <vector>
#include "string.h"

using namespace std;

class Room {
    public:
        Room(int, char *);
        int getID();
        char *getDescription();
        void setExit(int direction, Room *exit);
        Room *getExit(int exit);
        
        map<int, Room *> exits;
        char *description;
        int id;
};