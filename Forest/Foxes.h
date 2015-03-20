#include"Animal.h"

class Foxes : public Animal  {
private:
	struct fox {
		size_t birthDay;
		size_t lifeSpan;
		size_t reproductionTime;
		size_t offspring;
		size_t eat_day;
		size_t maxPride;
		fox(){
			birthDay = 1;								// date
			lifeSpan = 3;								// year
			reproductionTime = 365;						// day
			offspring = 5;								// pieces
			eat_day = 1;								// piece of rabbit
			maxPride = 5;								// pieces
		}
	};
public:
	fox* pride;
	size_t size;

	Foxes(size_t size, size_t day);
	~Foxes();

	Foxes(const Foxes& ob);

	fox* Birth_Die(fox* pride, int pieces, size_t day);

	virtual size_t eat();
};