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
int deleting();
int show_my_kart();

int main() {
	std::cout << "Hello there, what you want to do?" << std::endl;
	while (true) {
		std::cout << "1) Update staffs from file" << std::endl;
		std::cout << "2) Update stuffs manual" << std::endl;
		std::cout << "3) Start shopping" << std::endl;
		std::cout << "4) Show my kart" << std::endl;
		std::cout << "5) Clear console" << std::endl;
		std::cout << "-1) Exit" << std::endl;
		int choose = 0;
		std::cin >> choose;
		switch (choose)
		{
		case 1: {
			std::string path;
			std::cout << "Ok, write a path to txt file" << std::endl;
			std::cin >> path;
			int ret;
			ret = update_auto(path);
			if (ret == 1) {
				std::cout << "Cannot read name, check config file" << std::endl;
			}
			else if (ret == 2) {
				std::cout << "Cannot read price, check config file" << std::endl;
			}
			else if (ret == 0) {
				std::cout << "Done!" << std::endl <<std::endl;
				for (auto const& stuffs : st) {
					std::cout << '[' << stuffs.name << ';' << stuffs.price << ']' << std::endl;
				}
				std::cout << std::endl;
			}
			continue;
		}
		case 2:
			if (update_manual() == 1) std::cout << "You print wrong option, be careful. You were trow out manual update menu" << std::endl;
			std::cout << std::endl;
			break;
		case 3:
			shopping();
			std::cout << std::endl;
			break;
		case 4:
			show_my_kart();
			std::cout << std::endl;
			break;
		case 5:
			system("cls");
			break;
		case -1:
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
		while (1) {
			std::cin >> new_staff.price;
			if (new_staff.price <= 0) continue;
			st.push_back(new_staff);
			break;
		}
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
	st.clear();
	std::ifstream config;
	std::string line;
	config.open(path);
	while (config.is_open()) {
		std::getline(config, line);
		if (line.empty()) {
			config.close();
			return 0;
		}
		staff new_staff;
		new_staff.name = line.substr(line.find('[')+1, line.find_first_of(';')-1);
		new_staff.price = atoi(line.substr(line.find(';') + 1, line.find_first_of(']') - 1 - line.find(';')).c_str());
		if (new_staff.name.empty() == true || new_staff.price == 0) {
			if (new_staff.name.empty() == true) return 1;
			else if (new_staff.price <= 0) return 2;
		}
		else {
			st.push_back(new_staff);
		}
	}

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
int shopping() {
	std::cout << "If you want to quit, print in staff: \"-50\"" << std::endl;
	std::cout << "If you want to delete staff, print in staff: \"-100\"" << std::endl;
	while (1) {
		int count = 0;
		int choose = 0;
		int c;
		std::cout << "Which staff want you buy (print number of staff): " <<std::endl << std::endl ;
		for (auto const& stuffs : st) {
			std::cout << ++count << ") " << stuffs.name << " price : " << stuffs.price << std::endl;
		}
		std::cin >> choose;
		if (choose == -50) {
			break;
		}
		else if (choose == -100) {
			deleting();
			return 0;
		}
		else if (choose > st.size()) {
			std::cout << "wrong option, try again" << std::endl;
			continue;
		}
		std::cout << "print number of stuffs: ";
		std::cin >> c;
		purshase new_purshase(*std::next(st.begin(), choose-1), c);
		user_kart.add_pur(new_purshase);
	}
	return 0;
}
int deleting() {
	std::cout << "If you want to quit, print in staff: \"-50\"" << std::endl;
	while (1) {
		int count = 0;
		int choose = 0;
		int c;
		std::cout << "Which staff want you delete (print number of staff): " << std::endl << std::endl;
		for (auto & uk :user_kart.get_kart()) {
			std::cout << ++count << ") " << uk.get_name() << std::endl;
		}
		std::cin >> choose;
		if (choose == -50) {
			break;
		}
		else if (choose > st.size()) {
			std::cout << "wrong option, try again" << std::endl;
			continue;
		}
		user_kart.del_pur(choose);
	}
	return 0;
}
int show_my_kart() {
	user_kart.show();
	return 0;
}