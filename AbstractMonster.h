#pragma once
#include <string>
namespace MY {
    class AbstractMonster {
    protected:
        // Властивості монстра
        std::string name;
        int         health;

    public:
        // Абстрактний метод для виведення інформації про монстра
        virtual void printMonster() const = 0;

        AbstractMonster(const std::string name_, int health_);
        AbstractMonster(const AbstractMonster& other);
        AbstractMonster& operator=(const AbstractMonster& other);
        AbstractMonster(AbstractMonster&& other);
        AbstractMonster& operator=(AbstractMonster&& other);

        // Деструктор
        virtual ~AbstractMonster() = default;

        // Геттери властивостей монстра
        virtual const std::string& getName() const;
        virtual int getHealth() const;

        // Операція виводу
        friend std::ostream& operator<<(std::ostream& os, const AbstractMonster& monster);
    };

} // namespace MY
