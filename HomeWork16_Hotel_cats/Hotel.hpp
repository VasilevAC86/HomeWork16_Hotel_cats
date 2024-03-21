#pragma once
#include<iostream>
#include<memory>
#include<vector>
#include"Cat.hpp"

/*
* \brief Класс для создания объекта "Отель"
*/
class Hotel {
public:
	Hotel() :size_(0), capacity_(0) {} // Конструктор по умолчанию		
	/// <summary>
	/// Метод заполнения отеля котами
	/// Параметр "кол-во котов" передаём по ссылке, чтобы в случае, если кол-во котов больше номеров в отеле изменить эту переменную и в main
	/// </summary>
	/// <param name="quantity_cats">Кол-во котов</param>	
	void Fill_in(int &quantity_cats);
	/// Метод вывода в консоль данных об отеле
	void Print();
	/// Блок сэттеров
	void SetSize(int size) { this->size_ = size; }	
	/// Метод добавления кота в отель	
	void Add();
	/// <summary>
	/// Метод удаления кота из отеля
	/// </summary>
	/// <param name="number">Номер комнаты</param>
	void Remove();
	/// Блок гэттеров
	std::shared_ptr <Cat> begin()const { return cats_[0]; }
	std::shared_ptr <Cat> end()const { return cats_[size_-1]; }
	int size()const { return size_; }
	int GetCapacity()const { return capacity_; }		
	/// Метод поиска кота по имени, породе и владельцу			
	void SearchCat();
private:
	int size_; // Кол-во комнат
	//Cat* darr_; // Указатель на массив котов
	std::vector <std::shared_ptr <Cat>> cats_; // Вектор с умными указателями на котов	
	int capacity_; // Текущая вместимость отеля (кол-во оставшихся свободных номеров)
};