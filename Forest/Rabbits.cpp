#include"Rabbits.h"
	
Rabbits::Rabbits(size_t size){
	herd = new rab[size];
	this->size = size;
	cout << "Constructor Rabbits\n";
}

Rabbits::~Rabbits(){
	delete[] herd;
	cout << "Destructor Rabbits\n";
}

Rabbits::rab* Rabbits::Birth_Die(rab* herd, int pieces){
	if (pieces > 0){
		rab* newHerd = new rab[pieces];
		size = pieces;
		delete[] herd;
		return newHerd;
	}
	else{
		delete[] herd;
		size = 0;
		return nullptr;
	}
}
size_t Rabbits::eat() {
	return herd[0].eat_day * size;
}