#include "kart.h"

kart::kart() {

}
void kart::add_pur(purshase it) {
	this->kard.push_back(it);
}
void kart::del_pur(int num) {
	auto iter = kard.begin();
	for (int i = 0; i < num; i++) {
		iter++;
	}
	this->kard.erase(iter);
}
std::list<purshase> kart::get_kart() {
	return this->kard;
}