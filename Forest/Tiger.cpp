//#include <iostream>
//using namespace std;
//
//class Animal {
//public:
//	virtual void m(){
//		cout << "From Animal\n";
//	}
//};
//
//class Tiger : public Animal {
//public:
//	virtual void m(){
//		cout << "From Tiger\n";
//	}
//};
//
//
//
//
//int main() {
//	Animal* animal = nullptr;
//
//	animal = new Animal;
//	animal->m();
//	delete animal;
//
//	Tiger* tiger = new Tiger;
//	tiger->m();
//
//	animal = tiger;
//	animal->m();
//
//
//	delete tiger;
//
//	//Tiger* b = new Animal; WRONG
//
//
//	system("pause");
//}