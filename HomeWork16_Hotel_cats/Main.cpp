# include <iostream>

#include"Cat.hpp"
#include"Hotel.hpp"

int main() {
	// ========================== Шаг 1 - Ввод исходных данных (заполнение отеля котами) =========================
	int size_hotel; // Переменная для хранения размера отеля
	int quantity_cats; // Переменная для хранения кол-ва котов
	std::cout << "\033[93mEnter hotel size -> \033[0m";
	std::cin >> size_hotel;
	while (size_hotel < 1) { // Цикл проверки корректности введённого пользователем значения
		std::cout << "\033[91mInput error! The hotel size cannot be equal to or less than zero!\033[0m" \
			<< std::endl << "Enter hotel size ome more time -> ";
		std::cin >> size_hotel;
	}
	std::cout << "\033[93mEnter the quantity of cats -> \033[0m";
	std::cin >> quantity_cats;
	while (quantity_cats < 0) { // Цикл проверки корректности введённого пользователем значения
		std::cout << "\033[91mInput error! The quantity of cats cannot be less than zero!\033[0m" \
			<< std::endl << "Enter quantity of cats ome more time -> ";
		std::cin >> quantity_cats;
	}
	Hotel H; // Создаём отель
	H.SetSize(size_hotel); // Устан. размер отеля	
	H.Fill_in(quantity_cats); // Заполняем комнаты отеля котами
	H.Print(); // Выводим данные отеля в консоль

	// ========================== Шаг 2 - Добаление кота в отель =========================
	char my_choice = '0';
	do {
		std::cout << std::endl << "\033[93mDo you want to add a cat in the hotel?\033[0m" << std::endl \
			<< "Press \033[91m'0'\033[0m if you don't want \033[4mor\033[0m press \033[91many other key\033[0m if you want"\
			<< std::endl << "Your choice -> ";
		std::cin >> my_choice;
		if (my_choice != '0' && H.GetCapacity()) {
			H.Add();
			system("cls");
			H.Print();
		}
		if (!H.GetCapacity()) {
			std::cout << std::endl << "\033[92mThe hotel is full!\033[0m" << std::endl;
			break;
		}
	} while (my_choice != '0');

	// ========================== Шаг 3 - Поиск кота в отеле =========================
	std::cout << std::endl << "\033[93mDo need to find a cat in the hotel?\033[0m" << std::endl \
		<< "Press \033[91m'0'\033[0m if you don't need \033[4mor\033[0m press \033[91many other key\033[0m if you need"\
		<< std::endl << "Your choice -> ";
	std::cin >> my_choice;
	if (my_choice != '0')
		H.SearchCat();

	// ========================== Шаг 4 - Удаление кота из отеля =========================	
	do {
		std::cout << std::endl << "\033[93mDo need to remove a cat from the hotel?\033[0m" << std::endl \
			<< "Press \033[91m'0'\033[0m if you don't need \033[4mor\033[0m press \033[91many other key\033[0m if you need"\
			<< std::endl << "Your choice -> ";
		std::cin >> my_choice;
		if (my_choice != '0' && H.GetCapacity() != H.size()) {
			H.Remove();
			system("cls");
			H.Print();
		}
		if (H.GetCapacity() == H.size()) {
			std::cout << std::endl << "\033[92mThe hotel is empty!\033[0m" << std::endl;
			break;
		}
	} while (my_choice != '0');
	
	return 0;
}

