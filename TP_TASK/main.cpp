#include "kart.h"
#include "check.h"
#include "product.h"
#include "purshase.h"
#include <iostream>
#include <fstream>
#include <list>

//std::cout <<  << std::endl;

std::list<staff> st;
kart user_kart;
int update_auto(std::string path);
int update_manual();
int save_to_file(std::string path);
int shopping();
int show_my_kart();

int main() {
	std::cout << "Hello there, what you want to do?" << std::endl;
	while (true) {
		std::cout << "1) Update staffs from file" << std::endl;
		std::cout << "2) Update stuffs manual" << std::endl;
		std::cout << "3) Start shopping" << std::endl;
		std::cout << "4) Show my kart" << std::endl;
		std::cout << "Other) Exit" << std::endl;
		int choose = 0;
		std::cin >> choose;
		switch (choose)
		{
		case 1: {
			std::string path;
			std::cout << "Ok, write a path to txt file" << std::endl;
			std::cin >> path;
			if (update_auto(path) != 0) {
				std::cout << "Some went wrong, check log file" << std::endl;
			}
			else if (update_auto(path) == 0) {
				std::cout << "Done!" << std::endl <<std::endl;
				for (auto const& stuffs : st) {
					std::cout << '[' << stuffs.name << ';' << stuffs.price << ']' << std::endl;
				}
			}
			continue;
		}
		case 2:
			if (update_manual() == 1) std::cout << "You print wrong option, be careful. You were trow out manual update menu" << std::endl;
		case 3:

		case 4:

		default:
			exit(1);
		}
	}
}
int update_manual() {
	std::cout << "Print stuff's" << std::endl;
	int i = 0;
	while (true) {
		char ch;
		staff new_staff;
		int num = 0;
		std::cout << i + 1 << " staff" << std::endl;
		std::cout << "name: ";
		std::cin >> new_staff.name;
		std::cout << "price: ";
		std::cin >> new_staff.price;
		st.push_back(new_staff);
		std::cout << "do you want continue?(Y/N)" << std::endl;
		std::cin >> ch;
		getchar();
		if (ch == 'N' || ch == 'n') break;
		else if (ch != 'Y' && ch != 'y') {
			return 1;
		}
	}
	std::cout << "Do you want save it to file?(1-Yes)" << std::endl;
	std::cin >> i;
	std::string path;
	if (i == 1) {
		std::cout << "Print path to file (.txt)" << std::endl;
		std::cin >> path;
		if (save_to_file(path) == 0) std::cout << "Everuthing is fine" << std::endl;
	}
	return 0;
}
int update_auto(std::string path) {
	std::ifstream config;
	std::string line;
	config.open(path);
	while (std::getline(config, line)) {
		staff new_staff;
		new_staff.name = line.substr(line.find_first_of('[')+1, line.find_first_of(';')-1);
		new_staff.price = atoi(line.substr(line.find(';'), line.find_first_of(']')-1).c_str());
		if (new_staff.name.empty() == true || new_staff.price == 0) {
			return 1;
		}
		st.push_back(new_staff);
		config.close();
	}
	return 0;
}
int save_to_file(std::string path) {
	std::ofstream config;
	config.open(path);
	for (const auto& stuffs : st) {
		config << '[' << stuffs.name << ';' << stuffs.price << ']' <<std::endl;
	}
	config.close();
	return 0;
}