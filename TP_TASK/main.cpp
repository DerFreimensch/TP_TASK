#include "kart.h"
#include "check.h"
#include "product.h"
#include "purshase.h"
#include <iostream>
#include <list>

kart user_kart;

int main() {
	std::cout << "print 3 stuff" << std::endl;
	for (int i = 0; i < 3; i++) {
		staff new_staff;
		int num =0;
		std::cout << i + 1  << " staff" << std::endl;
		std::cout << "name: ";
		std::cin >> new_staff.name;
		std::cout << "price: ";
		std::cin >> new_staff.price;
		std::cout << "number of staff: ";
		std::cin >> num;
		purshase new_purshase(new_staff, num);
		user_kart.add_pur(new_purshase);
	}
	user_kart.show();
}