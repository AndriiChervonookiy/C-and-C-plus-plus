#include"Foxes.h"

Foxes::Foxes(size_t size, size_t day){
	pride = new fox[size];
	this->size = size;
	for (size_t i = 0; i < size; i++)
		pride[i].birthDay = day;
	cout << "Constructor Foxes.\n";
}

Foxes::~Foxes(){
	delete[] pride;
	cout << "Destructor Foxes.\n";
}

Foxes::Foxes(const Foxes& ob){
	pride = new fox[ob.size];
	if (!pride)
		exit(1);
	for (size_t i = 0; i < ob.size; i++)
		pride[i] = ob.pride[i];
	size = ob.size;
	cout << "Copy constructor Foxes!!!\n";
}

Foxes::fox* Foxes::Birth_Die(fox* pride, int pieces, size_t day){
	if (pieces > 0){
		fox* newPride = new fox[pieces];
		for (int i = 0; i < pieces; i++)
			newPride[i].birthDay = day;
		if (pieces >= (int)size) {
			for (size_t i = 0; i < size; i++)
				newPride[i].birthDay = pride[i].birthDay;
		}
		else {
			for (int i = 0; i < pieces; i++)
				newPride[i].birthDay = pride[i + (size - pieces)].birthDay;
		}
		size = pieces;
		delete[] pride;
		return newPride;
	}
	else{
		delete[] pride;
		size = 0;
		return nullptr;
	}
}

size_t Foxes::eat(){
	return pride[0].eat_day * size;
}