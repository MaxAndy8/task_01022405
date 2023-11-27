#include <iostream>
#include "AnyKindMonster.h"

int main() {

    system("chcp 1251>nul");

    // Ініціалізація монстрів з використанням auto і decltype
    auto orc = MY::AnyKindMonster<int>("Сергій", 100, MY::MonsterType::ORC, 6);
    decltype(orc) troll("Александр", 120, MY::MonsterType::TROLL, 8);

    // Виведення інформації про монстрів
    std::cout << orc << std::endl;    
    std::cout << troll << std::endl;

    auto gob = MY::AnyKindMonster<double>("Іван", 100, MY::MonsterType::ORC, 6.6);
    decltype(orc) zom("Юлія", 120, MY::MonsterType::ZOMBIE, 8.0);

    // Виведення інформації про монстрів
    std::cout << gob << std::endl;
    std::cout << zom << std::endl;



    return 0;
}