#include <iostream>
#include <string>

using namespace std;

// 1. define the inner struct object
// A struct that will hold player stats like strength, intelligence, and maximum health
struct PlayerStats {
    int strength;
    int intelligence;
    int max_health;
};

// 2. Define the outer struct
// A play with a username, a level, and a set of stats
struct Player {
    string username;
    int level;
    PlayerStats stats;
};

// 3. Access the elements of the player using dot notation
// We can print a player card
void show_player_card(Player p) {
    // Access the outer struct members
    cout << "PLAYER: " << p.username << endl;
    cout << "Level: " << p.level << endl;

    // Access the nested members
    cout << "Strength: " << p.stats.strength << endl;
    cout << "Intelligence: " << p.stats.intelligence << endl;
    cout << "HP: " << p.stats.max_health << endl;
}

int main() {
    // 4. Create the first character
    Player rogue;
    rogue.username = "Shadow";
    rogue.level = 12;

    // 5. Use dot notation for nested stats
    rogue.stats.strength = 13;
    rogue.stats.intelligence = 15;
    rogue.stats.max_health = 8;

    // 6. create a second instance - a second character
    Player wizard;
    wizard.username ="The Wise";
    wizard.level = 6;

    // 7. Set their stats
    wizard.stats.strength = 17;
    wizard.stats.intelligence = 19;
    wizard.stats.max_health = 13;

    // 8. Now print them!
    show_player_card(rogue);
    show_player_card(wizard);
}