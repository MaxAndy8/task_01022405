#include "AbstractMonster.h"

namespace MY {
AbstractMonster::AbstractMonster(const std::string name_, int health_)
    : name(name_), health(health_) {  }

AbstractMonster::AbstractMonster(const AbstractMonster& other) {
    name = other.name;
    health = other.health;
}

AbstractMonster& AbstractMonster::operator=(const AbstractMonster& other) {
    if (this != &other) {
        name   = other.name  ;
        health = other.health;
    }
    return *this;
}

AbstractMonster::AbstractMonster(AbstractMonster&& other) {
    name   = std::move(other.name);
    health = other.health;
    other.health = 0;
}

AbstractMonster& AbstractMonster::operator=(AbstractMonster&& other) {
    if (this != &other) {
        name = std::move(other.name);
        health = other.health;
        other.health = 0;
    }
    return *this;
}

// Реалізація геттерів
const std::string& AbstractMonster::getName() const {
    return name;
}

int AbstractMonster::getHealth() const {
    return health;
}

// Додана операція виводу
std::ostream& operator<<(std::ostream& os, const AbstractMonster& monster) {
    monster.printMonster();
    return os;
}

} // namespace MY