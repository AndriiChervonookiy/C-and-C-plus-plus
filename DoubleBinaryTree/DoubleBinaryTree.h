#pragma once
class DoubleBinaryTree {
	struct Element {
		Element* parent;
		double content;
		Element* left;
		Element* right;

		Element() {
			parent = nullptr;
			content = 0.0;
			left = nullptr;
			right = nullptr;
		}
	};

	Element* root;
	size_t size;

	bool insert(double content, Element*& current, Element* root);
	/*
		These both functions are implementing a pass across our tree 
		using a recursion in order to make a string for printing.
	*/
	char* makeStr(int lenght, int i, bool& m, Element* root, char*& strV, char*& strV2, char*& strH);
	char* makeStr(int lenght, int i, int& k, bool& m, Element* current, char*& NewStr, char*& strV, char*& strV2, char*& strH);
	/*
		This function is implementing a pseudographics and
		it is defining bool m in order to check exit from a loop.
	*/
	char* makeStr(int lenght, int i, bool& m, Element* current, char*& NewStr, char*& strV, char*& strV2, char*& strH);
	/*
		It is adding gaps to the string.
	*/
	char* Gap(int r);
	/*
		It is adding a line to the string.
	*/
	char* Line(int r);
	/*
		It is implementing a string with content.
	*/
	char* AddStr(Element* current, char* NewStr, int lenght, int r);
	/*
		It is implementing a string with upper vertical line.
	*/
	char* AddStrV(char* strV, int lenght, int r);
	/*
		It is implementing a string with under vertical line.
	*/
	char* AddStrV2(Element* current, char* strV2, int lenght, int r);
	/*
		It is implementing a string with horizontal line.
	*/
	char* AddStrH(Element* current, char* strH, int lenght, int r);

	/*
		This function is implementing a traverse across our tree
		using a recursion in order to find all tree leaves.
	*/
	bool FindLeaf(Element*& current, Element* root);
	/*
		It is deleting the leaf X.
	*/
	bool DelLeaf(Element* X);

	/*
		They are implementing right or left, big or small 
		TURN of the BRANCH.
	*/
	void RightTurn(Element*& current);
	void LeftTurn(Element*& current);
	void BigRightTurn(Element*& current);
	void BigLeftTurn(Element*& current);
	/*
		It is measure a height of a branch.	
		It is getting a node - root of this branch.		
	*/
	int BranchHight(Element* current, int& num, int& NMax);
	/*
		It is balancing a branch.
	*/
	void normalize(Element*& current);
	/*
		It is define heights of 4 branches 
		in order to determine kind of turn.
		k - hight of left branch minus hight of right branch.
	*/
	void kindTurn(Element* current, int& k, int& T1, int& T2, int& S1, int& S2);

public:
	DoubleBinaryTree();
	~DoubleBinaryTree();
	bool insert(double content);
	void exportToFile(char* fileName); //TODO записать в файл дерево в виде псевдографики
	void normalize(); //TODO равномерно распределить значения справа и слева от дерева
	
};