/*
* Daniel Patterson's program

1. writing documentation helps you understand code better because it tells you precisely what
the code is doing, and clarifies what certain names in code represent. 

2. well-documented code helps teams and open source communties thrive because it quickly
transfers knowledge about the code from just the original developer to a whole group of people, 
enabling them to refine it much more efficiently than if they had to intepret
the code before refining it.

3. contributing to clear documentation reflects social responsiblilty in tech because its what
we must do if we are to give our work to coworkers or customers and want them to build upon it or
easily use it, and if we want our code to outlive us and our careers.

4. One consequence of bad/no documentation is in the case of a highly complex program, 
no one will be able to use your code in development since they cant understand it.
Another consequence is you wont be able to share this code with others and recieve recognition for it
if they cant understand it.
*/



#include <iostream>
#include "DLL.h"
#include "SongNode.h"
#include <string>

using namespace std;

int main()
{
	string sName;
	string aName;
	string input;
	int position;
	int delPosition;
	cout << "What song would you like to add to the playlist?: ";
	//use getline to ensure the whole names are taken
	getline(cin, sName);
	cout << "Who wrote this song?: ";
	getline(cin, aName);
	//construct song instance
	songNode song(sName, aName);
	//construct playlist with created song
	DLL myList(&song);
	//print playlist
	cout << endl << myList.toString() << endl;

	cout << "Would you like to add another song, delete a song, or do neither?(Enter add if you want to add, delete if you want to delete, and anything else if you don't want to do either (this will end the program)): ";
	cin >> input;
	cin.ignore();
	//make loop for add and delete options
	while (input == "add" || input == "delete")
	{
		if (input == "add")
		{
			cout << endl << "What song would you like to add to the playlist?: ";
			getline(cin, sName);
			cout << "Who wrote this song?: ";
			getline(cin, aName);
			//construct new songs in loop by using keyword new with construct so the objects dont get overwritten by the following ones
			songNode* exSong = new songNode(sName, aName);

			cout << "At what postion do you want this song in the playlist?(Enter a number position you see or 1 greater than the last number to add it to the end of the playlist): ";
			cin >> position;
			//make loop while user inputs an invalid position to insert at, which outputs error message and has user try again
			while (position < 1 || position > myList.getSize() + 1)
			{
				cout << "wrong" << endl;
				cout << "At what postion do you want this song in the playlist?: ";
				cin >> position;
			}

			if (position == 1)
			{
				
				myList.insertAtBeg(exSong);
			}
			//if user enters a number which is 1 past the number of the last song, add to end
			else if (position == myList.getSize() + 1)
			{
				myList.insertAtEnd(exSong);
			}
			else
			{
				//for inserting in between songs
				myList.insertAtLocation(position, exSong);
			}
			//print playlist
			cout << endl << myList.toString() << endl;
			cin.ignore();
			cout << "Would you like to add another song, delete a song, or do neither?(Enter add if you want to add, delete if you want to delete, and anything else if you don't want to do either this will end the program): ";
			cin >> input;
			cin.ignore();
		}
		else
		{
			//make error message when user attempts to delete song from empty list
			if (myList.getSize() == 0)
			{
				cout << "You can't delete a song when there are no songs bro" << endl;
			}
			else
			{

				cout << endl << "What song would you like to delete?(Enter the number next to the song you want to delete): ";
				cin >> delPosition;
				cin.ignore();
				//checks for invalid delete positions
				while (delPosition < 1 || delPosition > myList.getSize())
				{
					cout << "404 no song found, please enter a vaild deletion number: ";
					cin >> delPosition;
					cin.ignore();
				}
				//deletes at beg
				if (myList.getSize() == 1 || delPosition == 1)
				{
					myList.deleteAtBeg();
				}
				//deletes at end when pos = pos of last song
				else if (delPosition == myList.getSize())
				{
					myList.deleteAtEnd();
				}
				//deletes a song between 2 others
				else
				{
					myList.deleteAtLocation(delPosition);
				}
				//prints the playlist
				cout << endl << myList.toString() << endl;
			}
			cout << endl << "Would you like to add another song, delete a song, or do neither?(Enter add if you want to add, delete if you want to delete, and anything else if you don't want to do either this will end the program): ";
			cin >> input;
			cin.ignore();
		}
		//prints the final playlist
		cout << endl << myList.toString();

	}
}