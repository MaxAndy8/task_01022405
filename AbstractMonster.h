#pragma once
#include <string>
namespace MY {
    class AbstractMonster {
    protected:
        // ���������� �������
        std::string name;
        int         health;

    public:
        // ����������� ����� ��� ��������� ���������� ��� �������
        virtual void printMonster() const = 0;

        AbstractMonster(const std::string name_, int health_);
        AbstractMonster(const AbstractMonster& other);
        AbstractMonster& operator=(const AbstractMonster& other);
        AbstractMonster(AbstractMonster&& other);
        AbstractMonster& operator=(AbstractMonster&& other);

        // ����������
        virtual ~AbstractMonster() = default;

        // ������� ������������ �������
        virtual const std::string& getName() const;
        virtual int getHealth() const;

        // �������� ������
        friend std::ostream& operator<<(std::ostream& os, const AbstractMonster& monster);
    };

} // namespace MY
