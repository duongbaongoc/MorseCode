/****************************************************************************************
* Name: Ngoc Bao Duong																	*
* Assignment: PA5 - CPTS 122															*
* Date created: 07/11/2017																*
* Last date edited: 07/12/2017															*
* File desciption: This file contains a program converting Englist character literals	*
*					read from a file to morse code and displaying the result.			*
* Note: using BST template - only work with type <char> - aptempting to make it also	*
*				work with <string>														*
***************************************************************************************/

#include "BST.h"

//this function generates the whole application
//the function opens convert.txt to read all literals from then converts them to morse codes
//and displays them to screen.
int main(void)
{
	BST<char> tree;
	char c = '\0';
	string line;
	int index = 0;
	std::ifstream infile("Convert.txt");
	cout << "This is the stree displayed through in order traversal: " << endl;
	tree.displayInOrder(); //print out the tree
	cout << "End displaying tree." << endl << endl << endl;
	cout << "Below is English character sentences and their converted morse codes:" << endl;

	while (!infile.eof()) //process until end of the convert file
	{
		std::getline(infile, line); //get a line from the convert.txt
		cout << "English characters: " << line << endl;
		c = line.at(0); //re-set the character to the first character of the line
		index = 0;
		cout << "Morse code: ";
		while (index < line.length()) //read until the end of each line
		{
			c = line.at(index); // extract one character from the line
			if (c == ' ') //if end of a morse string, print out three spaces
				cout << "   ";
			else //if the read char is any other char than a space
			{
				cout << tree.search(c) << " ";
			}
			index++;
		}
		cout << endl; 
	}

	cout << endl;
	infile.close();
	return 0;
}