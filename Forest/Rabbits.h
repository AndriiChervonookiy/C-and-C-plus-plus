#include"Animal.h"

class Rabbits: public Animal  {
private:
	struct rab {
		size_t reproductionTime;
		size_t offspring;
		size_t eat_day;
		rab(){
			reproductionTime = 210;						// day
			offspring = 10;								// pieces
			eat_day = 3;								// kg
		}
	};
public:
	rab* herd;
	size_t size;

	Rabbits(size_t size);
	~Rabbits();

	rab* Birth_Die(rab* herd, int pieces);

	virtual size_t eat(); 
};