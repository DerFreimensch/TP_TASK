#include "product.h"
product::product(){
	this->set_prod("Empty", 0);
}
product::product(std::string name_of_prod, int price) {
	this->set_prod(name_of_prod, price);
}
product::product(const product& A) {
	this->set_prod(A.value.name, A.value.price);
}
void product::set_prod(std::string name_of_prod, int price) {
	this->value.name = name_of_prod;
	this->value.price = price;
}
staff product::get_prod() {
	return value;
}