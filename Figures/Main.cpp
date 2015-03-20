#include"Square.h"
#include"Triangle.h"
#include "TriangleError.h"

int main(){
	try{
		Rectangle rectangle;
		rectangle.print();
		std::cout << "The rectangle perimeter =  " << rectangle.getPerimeter() << "\n\n";
		std::cout << "The rectangle square =  " << rectangle.getSquare() << "\n\n";

		std::cout << "-----------------------------------\n";
		Point S(16, 8), T(2, 5);
		Rectangle Rect(S, T);
		Rect.print();
		std::cout << "The rectangle perimeter =  " << Rect.getPerimeter() << "\n\n";
		std::cout << "The rectangle square =  " << Rect.getSquare() << "\n\n";


		Square square;
		square.print();


		std::cout << "-----------------------------------\n";
		Triangle triangle;
		triangle.print();
		std::cout << "The triangle perimeter =  " << triangle.getPerimeter() << "\n\n";
		std::cout << "The triangle square =  " << triangle.getSquare() << "\n\n";

		//std::cout << "-----------------------------------\n";
		//Point A(5, 5), B(10, 10), C(1, 2);
		//Triangle Big(A, B, C);
		//Big.print();
		//std::cout << "The triangle perimeter =  " << Big.getPerimeter() << "\n\n";
		//std::cout << "The triangle square =  " << Big.getSquare() << "\n\n";



		std::cout << "-----------------------------------\n";
		Point D(5, 5), E(15, 15), F(15, 5);
		Triangle Next(D, E, F);
		Next.print();
		std::cout << "The triangle perimeter =  " << Next.getPerimeter() << "\n\n";
		std::cout << "The triangle square =  " << Next.getSquare() << "\n\n";

		std::cout << "-----------------------------------\n";
		Point G(5, 5), H(15, 15), J(5, 15);
		Triangle Second(G, H, J);
		Second.print();
		std::cout << "The triangle perimeter =  " << Second.getPerimeter() << "\n\n";
		std::cout << "The triangle square =  " << Second.getSquare() << "\n\n";



		std::cout << "-----------------------------------\n";
		Point K(5, 10), L(10, 5), M(5, 5);
		Triangle Third(K, L, M);
		Third.print();
		std::cout << "The triangle perimeter =  " << Third.getPerimeter() << "\n\n";
		std::cout << "The triangle square =  " << Third.getSquare() << "\n\n";

		std::cout << "-----------------------------------\n";
		Point N(5, 10), P(10, 5), R(10, 10);
		Triangle fourth(N, P, R);
		fourth.print();
		std::cout << "The triangle perimeter =  " << fourth.getPerimeter() << "\n\n";
		std::cout << "The triangle square =  " << fourth.getSquare() << "\n\n";


		std::cout << "-----------------------------------\n";
		Point N1(5, 10), P1(10, 5), R1(10, 20);
		Triangle five(N1, P1, R1);
		fourth.print();
		std::cout << "The triangle perimeter =  " << five.getPerimeter() << "\n\n";
		std::cout << "The triangle square =  " << five.getSquare() << "\n\n";
	}

catch (TriangleError te) {
	std::cout << "TriangleError is caught.\n";
	std::cout << te.getMessage() << "\n";
}
catch (...) {
	std::cout << "Incomprehensible error\n";
}

	system("pause");
	return 0;
}	