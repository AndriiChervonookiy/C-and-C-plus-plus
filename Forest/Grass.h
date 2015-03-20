#pragma once
#include"Island.h"

class Grass : public Island {
protected:
	double growSpeed;
	double relativeMaxWeight;
	size_t totalGrass;						
public:
	Grass(){
		growSpeed = 0.01;					//  kg per square meter per day	
		relativeMaxWeight = 0.5;			//  kg per square meter
		totalGrass = 0;						//  kg 
		cout << "Constructor Grass.\n";
	}
	~Grass(){
		cout << "Destructor Grass.\n";
	}
	size_t incrementPerDay(){
		return (size_t)(space * growSpeed);
	}
	size_t getTotalGrass(){
		return totalGrass;
	}
	void putTotalGrass(size_t totalGrass){
		this->totalGrass = totalGrass;
	}
	size_t getMaxWeight(){
		return (size_t)(space * relativeMaxWeight);
	}
};