#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include "Hotel.hpp"

void Hotel::Fill_in(int &quantity_cats) {
	// Массив кошачьих имён
	std::string arr_names[5] = { "Alvin", "Archie", "Aron", "Colin", "Tom" };
	// Массив кошачьих пород
	std::string arr_breeds[5] = { "American Bobtail", "Japanese Bobtail", "Persian", "Siamese", "Sphynx" };
	// Массив имён хозяев кошек
	std::string arr_owners[6] = { "Anderson", "Brian" , "Calvin", "Jack", "Morgan", "Jon" };
	srand(time(NULL));
	capacity_ = size(); // Пока отель не заселён, вместимость = кол-ву номеров
	if (quantity_cats > size()) { // Если кол-во кошек больше номеров в отеле
		std::cout << std::endl << "\033[91mThere are more cats than hotel rooms!\033[0m" << std::endl << \
			"The last cats will not be accommodated!" <<std::endl;
		quantity_cats = size(); // Отсекаем лишних кошек		
	}
	for (int i = 0; i < quantity_cats; ++i) { // Данные о котах заполняем рандомно, используя массивы со строками выше
		cats_.emplace_back(std::make_shared<Cat>(arr_names[rand() % 5], arr_breeds[rand() % 5], arr_owners[rand() % 6]));
		--capacity_; // Каждое новое заселение кота уменьшает кол-во свободных номеров
	}
	for (int i = quantity_cats; i < size(); ++i)
		cats_.emplace_back(std::make_shared<Cat>("empty", "empty", "empty"));
}

void Hotel::Print() {
	std::cout << std::endl << "\033[92mHotel information: \033[0m" << std::endl;
	int it = 0; // итератор для range base for
	for (auto&el:cats_) { // Цикл вывода в консоль данных о котах
		if ((*el).GetName() != "empty") // Если кот в номере есть
			std::cout << "Room " << it + 1 << ". \033[90mName is:\033[0m " << (*el).GetName() << \
			"\033[90m, breed is: \033[0m" << (*el).GetBreed() << "\033[90m, owner's name is: \033[0m" << (*el).GetOnwer();
		else // Если кота в номере нет
			std::cout << "Room " << it + 1 << " is free.";
		std::cout << std::endl;
		++it;
	}
}

void Hotel::Add() {	
	// Заполняем имя
	std::string str;
	std::cout << "Enter the cat's name -> ";
	std::cin >> str;
	(*cats_[size_ - capacity_]).SetName(str);
	// Заполняем породу		
	std::cout << "Enter the cat's breed -> ";
	std::cin >> str;
	(*cats_[size_ - capacity_]).SetBreed(str);
	// Заполняем владельца		
	std::cout << "Enter the cat's owner -> ";
	std::cin >> str;
	(*cats_[size_ - capacity_]).SetOwner(str);
	--capacity_;				
}

void Hotel::Remove() {
	if (capacity_ != size()) { // Если в отеле хоть кто-то есть
		int number;
		std::cout << "\033[93mEnter the number of the room where you want to remove the cat from -> \033[0m";
		std::cin >> number;
		// Цикл проверки корректности введённого пользователем значения
		while (number < 1 || number > size() || (*cats_.at(number - 1)).GetName() == "empty") {
			std::cout << "\033[91mInput error (out of range)! Or the room is free!\033[0m" \
				<< std::endl << "Enter numner's room ome more time -> ";
			std::cin >> number;
		}		
		(*cats_.at(number - 1)).SetName("empty");
		(*cats_.at(number - 1)).SetBreed("empty");
		(*cats_.at(number - 1)).SetOwner("empty");
		++capacity_;
		return;
	}
	std::cout << std::endl << "\033[92mThe hotel is empty!\033[0m" << std::endl;
}

void Hotel::SearchCat() {
	std::string cat, breed, owner; // Переменные для хранения имени кота, его породы и владельца
	std::cout << std::endl << "\033[93mEnter data for search a cat -> \033[0m" << std::endl << "Enter cat's name ->";
	std::cin >> cat;
	std::cout << "Enter cat's breed -> ";
	std::cin >> breed;
	std::cout << "Enter cat's owner -> ";
	std::cin >> owner;
	bool key = false; // Переменная для хранения ключа события (true - кот наёден, false - кот не найден)
	int it = 0; // Итератор range base for
	for (auto& el : cats_) {
		if (cat == (*el).GetName() && breed == (*el).GetBreed() && owner == (*el).GetOnwer()) {
			std::cout << std::endl << "\033[92mThe cat found! Its lives in room " << it + 1 << " of the hotel\033[0m" << std::endl;
			key = true;
		}
		++it;		
	}
	if (key)
		return;
	std::cout << std::endl << "\033[91mNo cat with these details found\033[0m" << std::endl;
}
