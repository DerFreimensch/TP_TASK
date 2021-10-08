#include "purshase.h"
#include "kart.h"
purshase::purshase() {
	this->name = "Empty";
	this->number = 0;
	this->price_for_one = 0;
	this->whole_price = 0;
}
purshase::purshase(staff product, int num) {
	this->name = product.name;
	this->number = num;
	this->price_for_one = product.price;
	this->whole_price = this->number + this->price_for_one;
}
purshase::purshase(const purshase& A) {
	this->name = A.name;
	this->number = A.number;
	this->price_for_one = A.price_for_one;
	this->whole_price = A.whole_price;
}

std::string purshase::get_name()
{
	return this->name;
}

int purshase::get_number()
{
	return this->number;
}

int purshase::get_price_for_one()
{
	return this->price_for_one;
}

int purshase::get_whole_price()
{
	return this->whole_price;
}
