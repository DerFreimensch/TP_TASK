#include "check.h"
#include "kart.h"
#include <iostream>

extern kart user_kart;
void check::show() {
	std::list<purshase> total_kart = user_kart.get_kart();
	int k = 0;
	std::cout << "place" << "     ";
	std::cout << "name" << purshase::pace(purshase::fill_string("name"));
	std::cout << "number" << "    ";
	std::cout << "total" << "     ";
	std::cout << "o_number" << "  " << std::endl;
	for (auto iter = total_kart.begin(); iter != total_kart.end(); iter++) {
		k++;
		std::cout 
			<< k << iter->pace(iter->fill_number(k))
			<< iter->get_name() << iter->pace(iter->fill_string(iter->get_name()))
			<< iter->get_number() << iter->pace(iter->fill_number(iter->get_number()))
			<< iter->get_whole_price() << iter->pace(iter->fill_number(iter->get_whole_price()))
			<< iter->get_price_for_one() << std::endl;
	}
}
