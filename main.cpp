#include "room.h"

using namespace std;

struct Item {
    char item_name[10];
    char item_description[100];
    Room *item_location;
};

void createItem(char *name, char *description, Room *location);
vector <Item> items;
vector <Room*> rooms;

int main() {
    int C;
    char command[100];

    bool n;
    bool e;
    bool s;
    bool w;
    bool up;
    bool down;

    // Rooms
    Room *player = new Room(0, "The character's inventory.");
    Room *outside = new Room(1, "outside the main entrance of a university");
    Room *movieTheater = new Room(2, "at a lecture theater at the edge of campus boundaries");
    Room *pub = new Room(3, "at the unofficial campus pub");
    Room *lab = new Room(4, "at the innovation lab");
    Room *office = new Room(5, "at the admin office");
    Room *basement = new Room(6, "in the office's basement");
    Room *parkingLot = new Room(7, "in the parking lot");
    Room *restaurant = new Room(8, "at an Italian restaurant");
    Room *metroStation = new Room(9, "at the metro station, where you can take a train into the city");
    Room *stadium = new Room(10, "at the stadium, where the college football team plays");
    Room *museum = new Room(11, "at the Museo, where the achievements of the university's great alumni are honored");
    Room *deli = new Room(12, "in the deli, the quick stop for snacks and sandwiches");
    Room *communityTheater = new Room(13, "at the community theater, where student-produced plays run year-round");
    Room *bookstore = new Room(14, "at the bookstore, which doubles as a study room as well");
    Room *convenienceStore = new Room(15, "at the convenience store, where students stock up on essentials");
    
    // Items
    createItem("bicycle", "This is a device for transportation.", outside);
    createItem("desk", "Do your work on this.", movieTheater);
    createItem("projector", "This allows you to see and learn.", movieTheater);
    createItem("chair", "Thank this for your comfort in class.", movieTheater);
    createItem("beer", "This is not good for you.", pub);
    createItem("cookie", "You can eat this.", movieTheater);
    createItem("ticket", "This is your ticket to the city.", metroStation);
    createItem("jersey", "Use this to show your support for the team!", stadium);
    createItem("plate", "Eat your food on this.", restaurant);
    createItem("drone", "If used responsibly, this can be a major part of the future.", lab);
    createItem("computer", "This helps power the university's systems.", office);
    createItem("book", "The topic of this type of item can span all sorts of categories, all across the spectrum", bookstore);
    createItem("chocolate", "This is the best food in the world.", convenienceStore);


    // Player
    createItem("You", "This is you!", metroStation);

    // Set exits for each room
        // metroStation
        metroStation->setExit(3, parkingLot);
        // parkingLot
        parkingLot->setExit(1, metroStation);
        parkingLot->setExit(2, restaurant);
        parkingLot->setExit(3, outside);
        parkingLot->setExit(4, stadium);
        // stadium
        stadium->setExit(2, parkingLot);
        // restaurant
        restaurant->setExit(3, movieTheater);
        restaurant->setExit(4, parkingLot);
        // outside
        outside->setExit(1, parkingLot);
        outside->setExit(2, movieTheater);
        outside->setExit(3, lab);
        outside->setExit(4, pub);
        // movieTheater
        movieTheater->setExit(1, restaurant);
        movieTheater->setExit(4, outside);
        // pub — it's a trapdoor w/ no exits; enter and you die
        // pub->setExit(2, outside);
        // lab
        lab->setExit(1, outside);
        lab->setExit(2, office);
        lab->setExit(3, museum);
        // office
        office->setExit(4, lab);
        office->setExit(6, basement);
        // basement
        basement->setExit(5, office);
        // museum
        museum->setExit(1, lab);
        museum->setExit(3, deli);
        // deli
        deli->setExit(1, museum);
        deli->setExit(2, bookstore);
        deli->setExit(4, communityTheater);
        // communityTheater
        communityTheater->setExit(2, deli);
        // bookstore
        bookstore->setExit(3, convenienceStore);
        bookstore->setExit(4, deli);
        // convenienceStore
        convenienceStore->setExit(1, bookstore);

    // Intro
    cout << "This is the World of Zuul." << endl;
    cout << "Enjoy!" << "\n" << endl;
    
    while (true) {
        C = 0;

        // Location
        cout << "\n\nYou are " << (items[13].item_location)->description << "." << endl;

        // The pub's a trap! (exit condition)
        if (strcmp((items[13].item_location)->description, "at the unofficial campus pub") == 0) {
            cout << "\nIt's a trap!" << endl;
            cout << "Many have fallen at the hands of this pub's simple trapdoor...you now join the club." << endl;
            cout << "However, I applaud your effort.\n" << endl;
            cout << "Thanks for playing!" << endl;
            return 0;
        }

        // List items
        cout << "\nAvailable items:" << endl;
        for (int i = 0; i < 13; i++) {
            if (items[i].item_location == items[13].item_location) {
                cout << "• " << items[i].item_name << endl;
                C++;
            }
        }
        if (C == 0) {
            cout << "[NONE]" << endl;
        }

        // List exits
        cout << "\nPotential exits:" << endl;
        if ((items[13].item_location)->getExit(1) != NULL) {
            cout << "• NORTH" << endl;
            n = true;
        } else {
            n = false;
        }
        if ((items[13].item_location)->getExit(2) != NULL) {
            cout << "• EAST" << endl;
            e = true;
        } else {
            e = false;
        }
        if ((items[13].item_location)->getExit(3) != NULL) {
            cout << "• SOUTH" << endl;
            s = true;
        } else {
            s = false;
        }
        if ((items[13].item_location)->getExit(4) != NULL) {
            cout << "• WEST" << endl;
            w = true;
        } else {
            w = false;
        }
        if ((items[13].item_location)->getExit(5) != NULL) {
            cout << "• UP" << endl;
            up = true;
        } else {
            up = false;
        }
        if ((items[13].item_location)->getExit(6) != NULL) {
            cout << "• DOWN" << endl;
            down = true;
        } else {
            down = false;
        }

        // Accept command input        
        cout << "\n> Enter command (GO, INVENTORY, GET, DROP, QUIT):" << endl;
        cin.getline(command, 81);
        for (int i = 0; i < strlen(command); i++) {
            command[i] = tolower(command[i]);
        }

        // 'QUIT' command
        if (strcmp(command, "quit") == 0) {
            cout << "Thanks for playing!" << endl;
            return 0;
        }

        // 'GO' command: accept further input
        if (strcmp(command, "go") == 0) {            
            cout << "> Which exit?" << endl;
            cin.getline(command, 81);
            for (int i = 0; i < strlen(command); i++) {
                command[i] = tolower(command[i]);
            }
            if (strcmp(command, "north") == 0 && n) {
                items[13].item_location = items[13].item_location->getExit(1);
            } else if (strcmp(command, "east") == 0 && e) {
                items[13].item_location = items[13].item_location->getExit(2);
            } else if (strcmp(command, "south") == 0 && s) {
                items[13].item_location = items[13].item_location->getExit(3);
            } else if (strcmp(command, "west") == 0 && w) {
                items[13].item_location = items[13].item_location->getExit(4);
            } else if (strcmp(command, "up") == 0 && up) {
                items[13].item_location = items[13].item_location->getExit(5);
            } else if (strcmp(command, "down") == 0 && down) {
                items[13].item_location = items[13].item_location->getExit(6);
            } else {
                cout << "That's not a valid exit!" << endl;
            }
        }

        // 'GET' command: accept further input
        if (strcmp(command, "get") == 0) {
            C = 0;            
            cout << "> Which item?" << endl;
            cin.getline(command, 81);
            for (int i = 0; i < strlen(command); i++) {
                command[i] = tolower(command[i]);
            }

            if (strcmp(command, "quit") == 0) {
                cout << "Thanks for playing!" << endl;
                return 0;
            }

            for (int i = 0; i < 13; i++) {
                if (items[i].item_location == items[13].item_location) {
                    if (strcmp(command, items[i].item_name) == 0) {
                        C++;
                        items[i].item_location = player;
                    }
                }
            }
            if (C == 0) {
                cout << "That's not a valid item!" << endl;
            }
        }

        // 'INVENTORY' command
        if (strcmp(command, "inventory") == 0) {
            cout << "\nYour inventory:" << endl;
            C = 0;
            for (int i = 0; i < 13; i++) {
                if (items[i].item_location == player) {
                    cout << "• " << items[i].item_name << endl;
                    C++;
                }
            }
            if (C == 0) {
                cout << "[NONE]" << endl;
            }
        }

        // 'DROP' command: accept further input
        if (strcmp(command, "drop") == 0) {            
            cout << "Which item?" << endl;
            cin.getline(command, 81);

            for (int i = 0; i < strlen(command); i++) {
                command[i] = tolower(command[i]);
            }

            for (int i = 0; i < 13; i++) {
                if (items[i].item_location == player) {
                    if (strcmp(command, items[i].item_name) == 0) {
                        items[i].item_location = items[13].item_location;
                    }
                }
            }
        }
    }

    return 0;
}

void createItem(char *name, char *description, Room *location) {
    Item i;

    strcpy(i.item_name, name);
    strcpy(i.item_description, description);
    i.item_location = location;

    items.push_back(i);
}