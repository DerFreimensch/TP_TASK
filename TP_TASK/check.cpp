#include "check.h"
#include "kart.h"
#include <iostream>

extern kart user_kart;
void check::show() {
	std::list<purshase> total_kart = user_kart.get_kart();
	int k = 0;
	for (auto iter = total_kart.begin(); iter != total_kart.end(); iter++) {
		k++;
		std::cout << k << " " << iter->get_name() << " " << iter->get_number() << " " << iter->get_whole_price() << " " << iter->get_price_for_one() << std::endl;
	}
}