#pragma once
#include <string>
struct staff
{
	std::string name;
	int price;
};
class product
{
public:
	product();
	product(std::string name_of_prod, int price);
	product(const product& A);
	void set_prod(std::string name_of_prod, int price);
	staff get_prod();
private:
	staff value;
};

