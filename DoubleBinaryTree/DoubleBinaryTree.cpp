#include"DoubleBinaryTree.h"
#include<stdio.h>

#include<iostream>
using namespace std;

DoubleBinaryTree::DoubleBinaryTree(){
	root = nullptr;
	size = 0;
}

DoubleBinaryTree::~DoubleBinaryTree(){  //-------------------------------------------------
	if (size != 0) {
			FindLeaf(this->root, nullptr);
	}
}

bool DoubleBinaryTree::FindLeaf(Element*& current, Element* root)
{
	if (current->left != nullptr)
		FindLeaf(current->left, current);
	
	if (current->right != nullptr)
		FindLeaf(current->right, current);

	if (current->left == nullptr  &&  current->right == nullptr)
	{
		DelLeaf(current);
		return true;
	}
	return false;
}

bool DoubleBinaryTree::DelLeaf(Element* current)
{
	Element* tmp = current;
	if (current->parent != nullptr) {
		current = current->parent;
		if (current->left == tmp) current->left = nullptr;
		if (current->right == tmp) current->right = nullptr;
		cout << "Leaf is deleted:  " << tmp->content;
		delete tmp;
		size--;
		cout << ",   size =  " << size << "\n";
		return true;
	}
	else if (current->left == nullptr  && current->right == nullptr){
		root = nullptr;
		cout << "Leaf is deleted:  " << tmp->content ;
		delete tmp;
		size--;
		cout << ",   size =  " << size << "\n";
		return true;
	}
	return false;
}

bool DoubleBinaryTree::insert(double content) {
	return insert(content, this->root, nullptr);
}

bool DoubleBinaryTree::insert(double content, Element*& current, Element* root) {
	Element* newElement = new Element;
	newElement->content = content;	

	if (current == nullptr) {
		current = newElement;
		newElement->parent = root;
		size++;
		return true;
	}
	if (content == current->content) 
		return false;
	
	if (content > current->content) 
		insert(content, current->right, current);
	
	else 
		insert(content, current->left, current);
	
	return true;
}


void DoubleBinaryTree::exportToFile(char* fileName) //------------------------------------
{
	if (root == nullptr)		
		return;
	
	FILE* ptrf;
	fopen_s(&ptrf, fileName, "a");
	if (ptrf == nullptr) 
		return;

	/*
		This length should be power of 2 (+2 for "\n").
	*/
	int lenght = 64 + 2 ;

	for (size_t i = 1; ; i++)
	{
		char* str = new char[lenght + 1];		// str - content;
		str[0] = '\0';
		char* strV = new char[lenght + 1];		// strV - vertical line;
		strV[0] = '\0';
		char* strV2 = new char[lenght + 1];		// strV2 - second vertical line;
		strV2[0] = '\0';
		char* strH = new char[lenght + 1];		// strH - horizontal lines.
		strH[0] = '\0';

		bool m = false;			// m is checking: Is there any child for this level.
		str = makeStr(lenght, i, m, root, strV, strV2, strH);
		if (m == false) break;

		strcat_s(str, lenght + 1, "\n");
		strcat_s(strV, lenght + 1, "\n");
		strcat_s(strV2, lenght + 1, "\n");
		strcat_s(strH, lenght + 1, "\n");
		cout << strV << str << strV2 << strH;

		if (strlen(strV) != 0)
			fputs(strV, ptrf);
		if (strlen(str) != 0)
			fputs(str, ptrf);
		if (strlen(strV2) != 0)
			fputs(strV2, ptrf);
		if (strlen(strH) != 0)
			fputs(strH, ptrf);

		delete[] str;
		delete[] strV;
		delete[] strV2;
		delete[] strH;
	}
	fclose(ptrf);
}

char* DoubleBinaryTree::makeStr(int lenght, int i, bool& m, Element* root, char*& strV, char*& strV2, char*& strH)
{
	int k = 0;
	char* NewStr = new char[lenght + 1];
	NewStr[0] = '\0';
	return makeStr(lenght, i, k, m, this->root, NewStr, strV, strV2, strH);
}

char* DoubleBinaryTree::makeStr(int lenght, int i, int& k, bool& m, Element* current, char*& NewStr, char*& strV, char*& strV2, char*& strH)
{
	k++;

	if (k < i){
		if (current != nullptr) makeStr(lenght, i, k, m, current->left, NewStr, strV, strV2, strH);
		else makeStr(lenght, i, k, m, nullptr, NewStr, strV, strV2, strH);
	}
	
	if (k == i) NewStr = makeStr(lenght, i, m, current, NewStr, strV, strV2, strH);

	if (k < i){
		if (current != nullptr) makeStr(lenght, i, k, m, current->right, NewStr, strV, strV2, strH);
		else makeStr(lenght, i, k, m, nullptr, NewStr, strV, strV2, strH);
	}

	k--;
	return NewStr;
}

char* DoubleBinaryTree::makeStr(int lenght, int i, bool& m, Element* current, char*& NewStr, char*& strV, char*& strV2, char*& strH)
{
	int r = (int)((lenght-2) / (pow(2.0, i - 1) * 4));
	if (current != nullptr) 
	{
		m = true;

		NewStr = AddStr(current, NewStr, lenght, r);
		strV = AddStrV(strV, lenght, r);
		strV2 = AddStrV2(current, strV2, lenght, r);
		strH = AddStrH(current, strH, lenght, r);
	}
	else {
		for (int i = 0; i < 4; i++)	{
			strcat_s(NewStr, lenght + 1, Gap(r));
			strcat_s(strV, lenght + 1, Gap(r));
			strcat_s(strV2, lenght + 1, Gap(r));
			strcat_s(strH, lenght + 1, Gap(r));
		}
	}
	return NewStr;
}

char* DoubleBinaryTree::AddStr(Element* current, char* NewStr, int lenght, int r)
{
	char* TempStr = new char[50];
	TempStr[0] = '\0';

	int d = (int)(current->content);
	sprintf_s(TempStr, 50 , "%d", d);
	int Lleft = strlen(TempStr) / 2;
	int Lright = strlen(TempStr) - Lleft;

	strcat_s(NewStr, lenght + 1, Gap(r - Lleft));
	strcat_s(NewStr, lenght + 1, Gap(r));
	strcat_s(NewStr, lenght + 1, TempStr);
	strcat_s(NewStr, lenght + 1, Gap(r));
	strcat_s(NewStr, lenght + 1, Gap(r - Lright));

	delete[] TempStr;
	return NewStr;
}


char* DoubleBinaryTree::AddStrV(char* strV, int lenght, int r)
{
	strcat_s(strV, lenght + 1, Gap(r));
	strcat_s(strV, lenght + 1, Gap(r));
	strcat_s(strV, lenght + 1, ":");
	strcat_s(strV, lenght + 1, Gap(r));
	strcat_s(strV, lenght + 1, Gap(r - 1));
	return strV;
}


char* DoubleBinaryTree::AddStrV2(Element* current, char* strV2, int lenght, int r)
{
	strcat_s(strV2, lenght + 1, Gap(r));
	strcat_s(strV2, lenght + 1, Gap(r));
	if (current->left != nullptr || current->right != nullptr)
		strcat_s(strV2, lenght + 1, ":");
	else strcat_s(strV2, lenght + 1, " ");
	strcat_s(strV2, lenght + 1, Gap(r));
	strcat_s(strV2, lenght + 1, Gap(r - 1));
	return strV2;
}


char* DoubleBinaryTree::AddStrH(Element* current, char* strH, int lenght, int r)
{
	strcat_s(strH, lenght + 1, Gap(r));
	if (current->left != nullptr)
		strcat_s(strH, lenght + 1, Line(r));
	else strcat_s(strH, lenght + 1, Gap(r));
	if (current->left != nullptr || current->right != nullptr)
		strcat_s(strH, lenght + 1, "^");
	else strcat_s(strH, lenght + 1, " ");
	if (current->right != nullptr)
		strcat_s(strH, lenght + 1, Line(r));
	else strcat_s(strH, lenght + 1, Gap(r));
	strcat_s(strH, lenght + 1, Gap(r - 1));
	return strH;
}

char* DoubleBinaryTree::Gap(int r)
{
	char* Gap = new char[r + 1];
	Gap[0] = '\0';
	for (int j = 0; j < r; j++)	
		strcat_s(Gap, r+1, " ");
	return Gap;
}

char* DoubleBinaryTree::Line(int r)
{
	char* Line = new char[r + 1];
	Line[0] = '\0';
	for (int j = 0; j < r; j++)
		strcat_s(Line, r+1, "-");
	return Line;
}

void DoubleBinaryTree::normalize()	// --------------------------------------------
{
	if (root == nullptr)
		return;
	else 
		normalize(root);
}

void DoubleBinaryTree::normalize(Element*& current)	// --------------------------------------------
{
	if (current == nullptr)
		return;

	if (current->left == nullptr && current->right == nullptr)
		return;

	if (size <= 2)
		return;
	
	int k, T1, T2, S1, S2;
	do {
		kindTurn(current, k, T1, T2, S1, S2);

		if (k > 0)
		{
			if (S1 > 0)
				BigRightTurn(current);

			if (T1 > 0)
				RightTurn(current);
			else break;
		}

		if (k < 0)
		{
			if (S2 > 0)
				BigLeftTurn(current);

			if (T2 > 0)
				LeftTurn(current);
			else break;
		}

	} while (k < -1 || k > 1);

	if (current->left != nullptr)
		normalize(current->left);			

	if (current->right != nullptr)
		normalize(current->right);				 
}

void DoubleBinaryTree::kindTurn(Element* current, int& k, int& T1, int& T2, int& S1, int& S2)
{
	int n1, N1, n2, N2, n3, N3, n4, N4;
	n1 = N1 = n2 = N2 = n3 = N3 = n4 = N4 = 0;

	if (current->left != nullptr)
	{
		N1 = BranchHight(current->left->left, n1, N1);
		N2 = BranchHight(current->left->right, n2, N1);
	}

	if (current->right != nullptr)
	{
		N3 = BranchHight(current->right->left, n3, N3);
		N4 = BranchHight(current->right->right, n4, N4);
	}

	int Nleft, Nright;
	if (N1 > N2) Nleft = N1;
	else Nleft = N2;
	if (N3 > N4) Nright = N3;
	else Nright = N4;

	k = Nleft - Nright;
	T1 = N1 - Nright;
	T2 = N4 - Nleft;
	S1 = N2 - N1;
	S2 = N3 - N4;
}

void DoubleBinaryTree::RightTurn(Element*& current)
{
	Element* NewRoot = current->left;		//  We are creating a temporary pointer to new root.

	if (NewRoot->right != nullptr)
		NewRoot->right->parent = current;	// We are redirecting right element of left branch.

	current->left = NewRoot->right;			// We are redirecting old root.

	NewRoot->right = current;				// We are redirecting temporary element (new root).
	NewRoot->parent = current->parent;		// We are redirecting parent of temporary element (new root).
	
	current->parent = NewRoot;				// We are redirecting parent of old root.
		
	current = NewRoot;
}

void DoubleBinaryTree::LeftTurn(Element*& current)
{
	Element* NewRoot = current->right;		

	if (NewRoot->left != nullptr)
		NewRoot->left->parent = current;

	current->right = NewRoot->left;		

	NewRoot->left = current;			
	NewRoot->parent = current->parent;

	current->parent = NewRoot;				

	current = NewRoot;
}

void DoubleBinaryTree::BigRightTurn(Element*& current)
{
	LeftTurn(current->left);
	RightTurn(current);
}
void DoubleBinaryTree::BigLeftTurn(Element*& current)
{
	RightTurn(current->right);
	LeftTurn(current);
}

int DoubleBinaryTree::BranchHight(Element* current, int& num, int& NMax)
{
	if (current == nullptr)
		return 0;
	else {
		num++;

		if (current->left != nullptr)
			BranchHight(current->left, num, NMax);

		if (current->right != nullptr)
			BranchHight(current->right, num, NMax);

		if (num > NMax) NMax = num;

		num--;
		return NMax;
	}
}
