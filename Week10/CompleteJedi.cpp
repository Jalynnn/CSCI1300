#include <iostream>
#include <string>
#include <iomanip>

class Jedi {
public:
    // --- Constructors ---
    Jedi();
    Jedi(std::string name, int hp, int mana, int attack, int defense);

    // --- Mutators (setters) ---
    void setTrain(int hours);     // trains and improves stats
    void setRest(double hours);   // restores mana

    // --- Accessors (getters) ---
    double getRest() const;       // check current mana/rest
    std::string getName() const;
    int getHitPoints() const;
    int getAttack() const;
    int getDefense() const;

    // --- Combat simulation ---
    void attackTarget(Jedi& target);
    void takeDamage(int amount);

    // --- Utility ---
    void printStatus() const;

private:
    std::string name;
    int hit_points;        // health
    double mana;           // energy for attacks/training
    int attack_strength;   // power when attacking
    int defense_strength;  // power when defending
};

// --- Constructors ---
Jedi::Jedi()
    : name("Unknown"), hit_points(100), mana(50.0),
      attack_strength(10), defense_strength(8) {}

Jedi::Jedi(std::string n, int hp, int m, int attack, int defense)
    : name(std::move(n)), hit_points(hp), mana(m),
      attack_strength(attack), defense_strength(defense) {}

// --- Mutators ---
void Jedi::setTrain(int hours) {
    if (hours <= 0) {
        std::cout << name << " must train for positive hours.\n";
        return;
    }

    if (mana < hours * 2) { // training consumes mana
        std::cout << name << " is too tired to train that long.\n";
        return;
    }

    std::cout << name << " trains for " << hours << " hours.\n";
    mana -= hours * 2; // consume mana
    attack_strength += hours / 2; // small attack gain
    defense_strength += hours / 3; // small defense gain
}

void Jedi::setRest(double hours) {
    if (hours <= 0) return;
    mana += hours * 3; // regain mana
    if (mana > 100.0) mana = 100.0;
}

// --- Accessors ---
double Jedi::getRest() const {
    return mana;
}

std::string Jedi::getName() const { return name; }
int Jedi::getHitPoints() const { return hit_points; }
int Jedi::getAttack() const { return attack_strength; }
int Jedi::getDefense() const { return defense_strength; }

// --- Combat Simulation ---
void Jedi::attackTarget(Jedi& target) {
    if (hit_points <= 0) {
        std::cout << name << " cannot attack — they are defeated.\n";
        return;
    }

    if (mana < 5) {
        std::cout << name << " is too tired to attack.\n";
        return;
    }

    int damage = attack_strength - (target.defense_strength / 2);
    if (damage < 0) damage = 0;

    std::cout << name << " attacks " << target.name
              << " for " << damage << " damage!\n";

    mana -= 5; // attacks consume mana
    target.takeDamage(damage);
}

void Jedi::takeDamage(int amount) {
    hit_points -= amount;
    if (hit_points < 0) hit_points = 0;
    if (hit_points == 0) {
        std::cout << name << " has been defeated.\n";
    }
}

// --- Utility ---
void Jedi::printStatus() const {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Jedi: " << name
              << " | HP: " << hit_points
              << " | Mana: " << mana
              << " | ATK: " << attack_strength
              << " | DEF: " << defense_strength
              << std::endl;
}

// --- Example usage ---
int main() {
    Jedi obi("Obi-Wan", 100, 60, 12, 10);
    Jedi anakin("Anakin", 120, 55, 15, 8);

    obi.printStatus();
    anakin.printStatus();

    std::cout << "\n-- Obi-Wan trains --\n";
    obi.setTrain(5);
    obi.printStatus();

    std::cout << "\n-- Anakin attacks Obi-Wan --\n";
    anakin.attackTarget(obi);
    obi.printStatus();

    std::cout << "\n-- Obi-Wan rests --\n";
    obi.setRest(4);
    std::cout << "Current mana: " << obi.getRest() << "\n";

    obi.printStatus();

    return 0;
}
