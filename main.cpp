#include <iostream>
#include "AnyKindMonster.h"

int main() {

    system("chcp 1251>nul");

    // ����������� ������� � ������������� auto � decltype
    auto orc = MY::AnyKindMonster<int>("�����", 100, MY::MonsterType::ORC, 6);
    decltype(orc) troll("���������", 120, MY::MonsterType::TROLL, 8);

    // ��������� ���������� ��� �������
    std::cout << orc << std::endl;    
    std::cout << troll << std::endl;

    auto gob = MY::AnyKindMonster<double>("����", 100, MY::MonsterType::ORC, 6.6);
    decltype(orc) zom("���", 120, MY::MonsterType::ZOMBIE, 8.0);

    // ��������� ���������� ��� �������
    std::cout << gob << std::endl;
    std::cout << zom << std::endl;



    return 0;
}