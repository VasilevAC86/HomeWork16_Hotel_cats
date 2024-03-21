#pragma once

#include<string>

/*
* \brief Класс для создания объекта "Кот"
*/
class Cat {
public:
	Cat() :name_("empty"), breed_("empty"), owner_("empty") {}
	Cat(std::string name, std::string breed, std::string owner) {
		this->breed_ = breed;
		this->name_ = name;
		this->owner_ = owner;
	}
	~Cat() {}
	// Блок сэттэров
	void SetName(std::string name) { this->name_ = name; }
	void SetBreed(std::string breed) { this->breed_ = breed; }
	void SetOwner(std::string owner) { this->owner_ = owner; }
	// Блок гэттеров
	std::string GetName() { return name_; }
	std::string GetBreed() { return breed_; }
	std::string GetOnwer() { return owner_; }
private:
	std::string name_; // Имя кота
	std::string breed_; // Порода 
	std::string owner_; // Владелец
};