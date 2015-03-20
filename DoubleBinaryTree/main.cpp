#include"DoubleBinaryTree.h"
#include<iostream>
int main(){
	DoubleBinaryTree tree;

	tree.insert(50);
	tree.insert(45);
	tree.insert(55);
	tree.insert(40);
	tree.insert(47);
	tree.insert(52);
	tree.insert(60); 
	tree.insert(51);
	tree.insert(53);
	tree.insert(49);
	tree.insert(35);
	tree.insert(37);
	tree.exportToFile("file_for_tree.txt");		// Printing of our tree.

	tree.~DoubleBinaryTree();			// Deleting of our tree.
	tree.exportToFile("file_for_tree.txt");
	std::cout << "---------------------------------------------------------------------\n";
	
	tree.insert(50);
	tree.insert(45);
	tree.insert(55);
	tree.insert(40);
	tree.insert(47);
	tree.insert(52);
	tree.insert(60);
	tree.insert(49);
	tree.insert(35);
	tree.insert(37);
	tree.exportToFile("file_for_tree.txt");
	tree.normalize();				// Balancing of our tree
	tree.exportToFile("file_for_tree.txt");
	tree.~DoubleBinaryTree();			// Deleting of our tree.	
	tree.exportToFile("file_for_tree.txt");
	std::cout << "---------------------------------------------------------------------\n";
	
	tree.insert(50);	
	tree.insert(45);
	tree.insert(55);
	tree.insert(52);
	tree.insert(60);
	tree.insert(63);
	tree.insert(64);
	tree.insert(54);
	tree.insert(57);
	tree.insert(47);
	tree.insert(43);
	tree.exportToFile("file_for_tree.txt");
	tree.normalize();				// Balancing of our tree
	tree.exportToFile("file_for_tree.txt");
	tree.~DoubleBinaryTree();			// Deleting of our tree.	
	tree.exportToFile("file_for_tree.txt");
	std::cout << "----------------------------------------------------------------------\n";

	for (int i = 0; i < 15; i++)
		tree.insert(15-i);
	tree.exportToFile("file_for_tree.txt");
	tree.normalize();				// Balancing of our tree
	tree.exportToFile("file_for_tree.txt");
	tree.~DoubleBinaryTree();			// Deleting of our tree.
	tree.exportToFile("file_for_tree.txt");
	std::cout << "---------------------------------------------------------------------\n";

	tree.insert(50);
	tree.insert(55);
	tree.insert(52);
	tree.insert(54);
	tree.insert(53);
	tree.exportToFile("file_for_tree.txt");
	tree.normalize();				// Balancing of our tree
	tree.exportToFile("file_for_tree.txt");
	tree.~DoubleBinaryTree();			// Deleting of our tree.	
	tree.exportToFile("file_for_tree.txt");
	std::cout << "---------------------------------------------------------------------\n";

	getchar();
}