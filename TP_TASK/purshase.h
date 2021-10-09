#pragma once
#include <string>
#include "product.h"
class purshase
{
public:
	purshase();
	purshase(staff product, int num);
	purshase(const purshase& A);
	void show();
	std::string get_name();
	int get_number();
	int get_price_for_one();
	int get_whole_price();
	std::string pace(int num);
	int fill_number(int A);
	int fill_string(std::string A);
private:
	std::string name;
	int number;
	int price_for_one;
	int whole_price;
};

