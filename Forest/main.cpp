//	Создать класс живущих с местоположением.
//	Определить наследуемые классы - лиса, кролик и трава.

//	Лиса ест кролика.
//	Кролик ест траву.
//	Лиса может умереть - определен возраст.
//	Кролик тоже может умереть.

//	Кроме этого определен класс - отсутствие жизни.

//	Если в окрестности имеется больше травы, чем кроликов, то трава остается, иначе трава съедена.
//	Если лис слишком старый он может умереть.
//	Если лис слишком много(больше 5 в окрестности), лисы больше не появляются.

//	Если кроликов меньше лис, то лис ест кролика.????????
//	Если кроликов меньше лис, то лисы съедят всех кроликов.

#include <iostream>
using namespace std;
#include"Grass.h"
#include"Rabbits.h"
#include"Foxes.h"

int main() {	
	Island island;
	size_t day;
	size_t noPlantSpan = 7;	// days
	while (island.getTime() < noPlantSpan)
	{
		day = island.getTime();
		cout << day << "\n";
		island.putTime(++day);
	}

	Grass grass;
	size_t tot;
	size_t noAnimalSpan = 70;
	while (island.getTime() < noPlantSpan + noAnimalSpan)
	{
		tot = grass.getTotalGrass();
		tot += grass.incrementPerDay();
		if (tot > grass.getMaxWeight())
			tot = grass.getMaxWeight();
		grass.putTotalGrass(tot);
		cout << island.getTime() << "\t" << tot << "\t" << grass.incrementPerDay() << "\n";
		island.putTime(++day);
	}

	Rabbits rabbits(150);
	size_t noFoxSpan = 200;
	while (island.getTime() < noPlantSpan + noAnimalSpan + noFoxSpan)
	{
		tot = grass.getTotalGrass();
		tot += grass.incrementPerDay();
		if (tot > grass.getMaxWeight())
			tot = grass.getMaxWeight();

		if (rabbits.herd != nullptr) 
		{
			if (tot > rabbits.eat())
				tot -= rabbits.eat();
			else {
				int die = (int)((rabbits.eat() - tot) / rabbits.herd[0].eat_day);
				rabbits.herd = rabbits.Birth_Die(rabbits.herd, rabbits.size - die);
				tot = 0;
			}
		}
		size_t RabSpan = island.getTime() - noPlantSpan - noAnimalSpan;
		if ((RabSpan) % (rabbits.herd[0].reproductionTime) == 0 && RabSpan != 0)
			rabbits.herd = rabbits.Birth_Die(rabbits.herd, rabbits.size + rabbits.size * rabbits.herd[0].offspring / 2);
		
		grass.putTotalGrass(tot);
		cout << island.getTime() << "\t" << tot << "\t" << rabbits.size << "\n";
		island.putTime(++day);
	}

	Foxes foxes(2, island.getTime());
	size_t FoxSpan = 1500;
	while (island.getTime() < noPlantSpan + noAnimalSpan + noFoxSpan + FoxSpan)
	{
		tot = grass.getTotalGrass();
		tot += grass.incrementPerDay();
		if (tot > grass.getMaxWeight())
			tot = grass.getMaxWeight();

		if (rabbits.herd != nullptr)
		{
			if (tot > rabbits.eat())
				tot -= rabbits.eat();
			else {
				int die = (int)((rabbits.eat() - tot) / rabbits.herd[0].eat_day);
				rabbits.herd = rabbits.Birth_Die(rabbits.herd, rabbits.size - die);
				tot = 0;
			}
		}
		size_t RabSpan = island.getTime() - noPlantSpan - noAnimalSpan;
		if (rabbits.size > 0){
			if ((RabSpan) % (rabbits.herd[0].reproductionTime) == 0 && RabSpan != 0)
				rabbits.herd = rabbits.Birth_Die(rabbits.herd, rabbits.size + rabbits.size * rabbits.herd[0].offspring / 2);
		}

		if (foxes.pride != nullptr)
		{
			if (rabbits.size > foxes.eat())
				rabbits.herd = rabbits.Birth_Die(rabbits.herd, rabbits.size - foxes.eat());
			else{
				int die = (int)((foxes.eat() - rabbits.size) / foxes.pride[0].eat_day);
				foxes.pride = foxes.Birth_Die(foxes.pride, foxes.size - die, island.getTime());
				rabbits.herd = rabbits.Birth_Die(rabbits.herd, 0);
			}
		}
		size_t FoxSpan = island.getTime() - noPlantSpan - noAnimalSpan - noFoxSpan;
		if (foxes.pride != nullptr){
			if ((FoxSpan) % (foxes.pride[0].reproductionTime) == 0 && FoxSpan != 0 && foxes.size < foxes.pride[0].maxPride)
				foxes.pride = foxes.Birth_Die(foxes.pride, foxes.size + foxes.size * foxes.pride[0].offspring / 2, island.getTime());
		}
		if (foxes.pride != nullptr){
			for (size_t i = 0; i < foxes.size; i++){
//				cout << foxes.pride[i].birthDay << " ";
				if (island.getTime() >= foxes.pride[i].birthDay + foxes.pride[i].lifeSpan * 365)
					foxes.pride = foxes.Birth_Die(foxes.pride, foxes.size - 1, island.getTime());
			}
//			cout << "\n";
		}

		grass.putTotalGrass(tot);
		cout << island.getTime() << "\t" << tot << "\t" << rabbits.size << "\t" << foxes.size << "\n";
		island.putTime(++day);
	}

	system("pause");
	return 0;
}