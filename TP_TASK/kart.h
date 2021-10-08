#pragma once
#include "purshase.h"
#include "check.h"
#include <list>
class kart :
	public check
{
private:
	std::list<purshase> kard;
public:
	kart();
	void add_pur(purshase it);
	void del_pur(int num);
	std::list<purshase> get_kart();
};

