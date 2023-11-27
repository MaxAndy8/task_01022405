#pragma once
#include <iostream>
#include <typeinfo>
#include "AbstractMonster.h"
#include "AnyKindMonster.h"

namespace MY {
	enum class MonsterType {
			ORC,
			TROLL,
			ZOMBIE,
			GOBLIN
		};

	// Клас, що описує будь-якого типу монстра
	template <typename T>
	class AnyKindMonster : public AbstractMonster {
		T contents;
	public:
		// Перелік констант для типів монстрів
		

		// Конструктор класу
		AnyKindMonster(std::string name, int health, MonsterType type, T val);

		AnyKindMonster(const AnyKindMonster& other);
		AnyKindMonster& operator=(const AnyKindMonster& other);
		AnyKindMonster(AnyKindMonster&& other);
		AnyKindMonster& operator=(AnyKindMonster&& other);

		// Реалізація абстрактного методу для виведення інформації про монстра
		void printMonster() const override;

	private:
		MonsterType type;
	};

	template <typename T>
	AnyKindMonster<T>::AnyKindMonster(std::string name_, int health_, MonsterType type_, T val_)
		: AbstractMonster(name_, health_), type(type_) , contents(val_) {}

	// Реалізація конструктора копіювання
	template <typename T>
	AnyKindMonster<T>::AnyKindMonster(const AnyKindMonster<T>& other) : AbstractMonster(other) {
		type = other.type;
		contents = other.contents;
	}

	// Реалізація оператора присвоєння
	template <typename T>
	AnyKindMonster<T>& AnyKindMonster<T>::operator=(const AnyKindMonster<T>& other) {
		if (this != &other) {
			AbstractMonster::operator=(other);
			type = other.type;
			contents = other.contents;
		}
		return *this;
	}

	// Реалізація конструктора переміщення
	template <typename T>
	AnyKindMonster<T>::AnyKindMonster(AnyKindMonster&& other)
		: AbstractMonster(std::move(other)) {
		type = other.type;
		contents = std::move(other.contents);
	}

	// Реалізація оператора переміщення
	template <typename T>
	AnyKindMonster<T>& AnyKindMonster<T>::operator=(AnyKindMonster<T>&& other) {
		if (this != &other) {
			AbstractMonster::operator=(std::move(other));
			type = other.type;
			contents = std::move(other.contents);
		}
		return *this;
	}

	template <typename T>
	void AnyKindMonster<T>::printMonster() const {
		std::cout << "Казкове чудовисько: " << name << std::endl;
		std::cout << "Типу: ";
		switch (type) {
		case MonsterType::ORC:
			std::cout << "Орк";
			break;
		case MonsterType::TROLL:
			std::cout << "Троль";
			break;
		case MonsterType::ZOMBIE:
			std::cout << "Зомбі";
			break;
		case MonsterType::GOBLIN:
			std::cout << "Гоблін";
			break;
		default:
			std::cout << "Невідомого типу";
		}
		std::cout << std::endl;
		std::cout << "Тип вмісту(начинки) чудовиська:      " << typeid(contents).name() << std::endl;
		std::cout << "Значення вмісту(начинки) чудовиська: " << contents << std::endl;
		std::cout << "Здоров'я: " << health << std::endl;
		std::cout << "----------------------" << std::endl;
	}





} // namespace MY


