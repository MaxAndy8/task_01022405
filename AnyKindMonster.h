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

	// ����, �� ����� ����-����� ���� �������
	template <typename T>
	class AnyKindMonster : public AbstractMonster {
		T contents;
	public:
		// ������ �������� ��� ���� �������
		

		// ����������� �����
		AnyKindMonster(std::string name, int health, MonsterType type, T val);

		AnyKindMonster(const AnyKindMonster& other);
		AnyKindMonster& operator=(const AnyKindMonster& other);
		AnyKindMonster(AnyKindMonster&& other);
		AnyKindMonster& operator=(AnyKindMonster&& other);

		// ��������� ������������ ������ ��� ��������� ���������� ��� �������
		void printMonster() const override;

	private:
		MonsterType type;
	};

	template <typename T>
	AnyKindMonster<T>::AnyKindMonster(std::string name_, int health_, MonsterType type_, T val_)
		: AbstractMonster(name_, health_), type(type_) , contents(val_) {}

	// ��������� ������������ ���������
	template <typename T>
	AnyKindMonster<T>::AnyKindMonster(const AnyKindMonster<T>& other) : AbstractMonster(other) {
		type = other.type;
		contents = other.contents;
	}

	// ��������� ��������� ���������
	template <typename T>
	AnyKindMonster<T>& AnyKindMonster<T>::operator=(const AnyKindMonster<T>& other) {
		if (this != &other) {
			AbstractMonster::operator=(other);
			type = other.type;
			contents = other.contents;
		}
		return *this;
	}

	// ��������� ������������ ����������
	template <typename T>
	AnyKindMonster<T>::AnyKindMonster(AnyKindMonster&& other)
		: AbstractMonster(std::move(other)) {
		type = other.type;
		contents = std::move(other.contents);
	}

	// ��������� ��������� ����������
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
		std::cout << "������� ����������: " << name << std::endl;
		std::cout << "����: ";
		switch (type) {
		case MonsterType::ORC:
			std::cout << "���";
			break;
		case MonsterType::TROLL:
			std::cout << "�����";
			break;
		case MonsterType::ZOMBIE:
			std::cout << "����";
			break;
		case MonsterType::GOBLIN:
			std::cout << "�����";
			break;
		default:
			std::cout << "��������� ����";
		}
		std::cout << std::endl;
		std::cout << "��� �����(�������) ����������:      " << typeid(contents).name() << std::endl;
		std::cout << "�������� �����(�������) ����������: " << contents << std::endl;
		std::cout << "������'�: " << health << std::endl;
		std::cout << "----------------------" << std::endl;
	}





} // namespace MY


