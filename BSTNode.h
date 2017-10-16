/****************************************************************************************
* Name: Ngoc Bao Duong																	*
* Assignment: PA5 - CPTS 122															*
* Date created: 07/11/2017																*
* Last date edited: 07/12/2017															*
* File desciption: This file contains a class template representing a BST node.			*
*				Two of the fields are <string> type and <T> type which can be either	*
*				<string> or <char>														*
***************************************************************************************/

#include <string>

using std::string;

template <class T> //T == char/string
class Node
{
	public:
	//constructors
		Node(); //default
		Node(T chars, string code); //parametrized
	//getters
		T &getChars();
		string &getCode();
		Node * &getPLeft();
		Node * &getPRight();
	//setters
		void setChars(T chars);
		void setCode(string code);
		void setPLeft(Node *node);
		void setPRight(Node *node);
	private:
		T mChars;
		string mCode;
		Node *mPLeft;
		Node *mPRight;
};

//default constructor
template <class T>
Node<T>::Node() 
{
	mCode = "";
	mPLeft = nullptr; 
	mPRight = nullptr;
}

//parametrized constructor
template <class T>
Node<T>::Node(T chars, string code)
{
	mChars = chars;
	mCode = code;
	mPLeft = nullptr;
	mPRight = nullptr;
}

//get English characters
template <class T>
T & Node<T>::getChars()
{
	return mChars;
}

//get Morse code
template <class T>
string & Node<T>::getCode()
{
	return mCode;
}

//get pointer to left child
template <class T>
Node<T> * & Node<T>::getPLeft()
{ 
	return mPLeft; 
}

//get pointer to right child
template <class T>
Node<T> * & Node<T>::getPRight()
{
	return mPRight;
}

//assign English characters
template <class T>
void Node<T>::setChars(T chars)
{
	mChars = chars;
}

//assign morse code
template <class T>
void Node<T>::setCode(string code)
{
	mCode = code;
}

//assign left child
template <class T>
void Node<T>::setPLeft(Node *pLeft)
{
	mPLeft = pLeft;
}

//assign right child
template <class T>
void Node<T>::setPRight(Node *pRight)
{
	mPRight = pRight;
}
