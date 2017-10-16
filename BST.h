/****************************************************************************************
* Name: Ngoc Bao Duong																	*
* Assignment: PA5 - CPTS 122															*
* Date created: 07/11/2017																*
* Last date edited: 07/12/2017															*
* File desciption: This file contains a class template representing a BST. The BST has	*
*				nodes which are also a class template declared in BSTNode.h.			*
***************************************************************************************/

#include <iostream>
#include <fstream>
#include "BSTNode.h"
#include "String.h"

using std::cout;
using std::endl;
using std::getline;
using std::fstream;

template <class T> //T == char/string. BST<T> does not work well with string
class BST
{
	public:
		//default constructor
		BST();
		//setter
		void setPRoot(Node<T> *node);
		//getter
		Node<T> *&getPRoot();
		//other member functions
		void insert(T chars, string code);
		void displayInOrder();
		string & search(T & chars);
		//destructor
		~BST<T>();
	private:
	Node<T> *mPRoot;
	void insert(Node<T> *node, Node<T> *&pRoot);
	void displayInOrder(Node<T> *&pRoot);
	string & search(T & chars, Node<T> *&pRoot);
};

//default constructor: 
//open MorseTable.txt to read, create node for each character, insert to the tree, close the file
template <class T>
BST<T>::BST()
{
	mPRoot = nullptr;
	T chars, discarded;
	string code;
	fstream infile("MorseTable.txt"); //open file to read
	
	while (!infile.eof()) //process until end of file
	{
		infile >> chars; //read the English character
		infile >> discarded >> discarded; //discard unrelated characters
		getline(infile, code, '\n'); //read the corresponding morse code
		Node<T>  *node = new Node<T>(chars, code); //make a node
		insert(node, mPRoot); //insert the node to the tree
	}

	infile.close();
}

//getter
template <class T>
Node<T> *& BST<T>::getPRoot()
{ 
	return mPRoot; 
}

//setter
template <class T>
void BST<T>::setPRoot(Node<T> *node)
{
	mPRoot = node;
}

//destructor - using iteration - post order
template <class T>
BST<T>::~BST<T>()
{
	Node<T> *pCur = mPRoot, *pParent = nullptr;
	std::cout << "Inside BST destruct: " << std::endl;

	while (mPRoot != nullptr) //keep doing until the root is deleted
	{
		pCur = mPRoot;
		while (pCur->getPLeft() != nullptr || pCur->getPRight() != nullptr) //while pCur is not a leaf -> find leaf
		{
			while (pCur->getPLeft() != nullptr) //find the most left node
			{
				pParent = pCur;
				pCur = pCur->getPLeft();
			}
			if (pCur->getPRight() != nullptr) //check if the left most node has a right child
			{
				pParent = pCur;
				pCur = pCur->getPRight();
			}
		}
		//set parent pointer to null
		if (mPRoot->getPLeft() == nullptr && mPRoot->getPRight() == nullptr)
			setPRoot(nullptr);
		else if (pParent->getPLeft() == pCur)
			pParent->setPLeft(nullptr);
		else //(pParent->getPRight() == pCur)
			pParent->setPRight(nullptr);
		delete pCur;
	}
	std::cout << "Leaving BST destructor..." << std::endl;
}

//insert new info  to BST in order - public function
template <class T>
void BST<T>::insert(T chars, string code)
{
	Node<T> *node = new Node<T>(chars, code);
	insert(node, mPRoot); //call the helper function
}

//helper for the public insert function
//insert new node to BST in order - private function
template <class T>
void BST<T>::insert(Node<T> *node, Node<T> *&pRoot)
{
	if (pRoot == nullptr) //empty tree
		pRoot = node;
	else if (node->getChars() < pRoot->getChars()) //new node is less than current node, go left
		insert(node, pRoot->getPLeft());
	else //new node is greater than current node, go right
		insert(node, pRoot->getPRight());
}

//display BST using in order traversal - public function
template <class T>
void BST<T>::displayInOrder()
{
	displayInOrder(mPRoot); //call the helper function
	cout << std::endl;
}

//display BST using in order traversal - private function
//helper for the public display function
template <class T>
void BST<T>::displayInOrder(Node<T> *&pRoot)
{
	if (pRoot != nullptr)
	{
		displayInOrder(pRoot->getPLeft()); //go left
		cout << pRoot->getChars() << " == " << pRoot->getCode() << endl; //process root
		displayInOrder(pRoot->getPRight()); //go right
	}
}

//search for Morse code of the given English literal
//using post order traversal - public function
template <class T>
string & BST<T>::search(T & chars)
{
	chars = toupper(chars); //search regardless of upper case or lower case
	return search(chars, mPRoot);
}

//help to search for Morse code of the given English literal
//using post order traversal - private function
template <class T>
string & BST<T>::search(T & chars, Node<T> *&pRoot)
{
	if (pRoot == nullptr) //if reach the end of tree but character not found
	{
		cout << "No word/char - morse code found";
		string result;;
		return result;
	}
	else if (pRoot->getChars() == chars) //found the character
		return pRoot->getCode();
	else if (pRoot->getChars() > chars) //the character is on the left of the current node
		search(chars, pRoot->getPLeft());
	else //the character is on the right of the current node
		search(chars, pRoot->getPRight());
}