#include "DLL.h"
#include <iostream>
#include <string>
using namespace std;

DLL::DLL(songNode* first) //construct the playlist when taking in a song node as the start of the list
{
	//set global index to this first song
	index = first;
	//set start to it
	startIndex = first;
	//set end to it since when the list is constructed there is only 1 node
	endIndex = first;
	//set size to 1
	size = 1;
}

songNode DLL::getCurrent()
{
	//accesses the global index pointer outside of the class
	return *index;
}

int DLL::getSize()
{
	//accesses the playlist size outside of the class
	return size;
}

void DLL::setCurrent(songNode* nS)
{
	//sets the global index to a specified song pointer 
	index = nS;
}

void DLL::goToNext()
{
	//moves global index to its next song node
	index = (*index).getNext();
}

void DLL::goToPrev()
{
	//moves global index to its prev song node
	index = (*index).getPrev();
}

void DLL::insertAtLocation(int i, songNode* s)
{
	//starts for loop at the beginnign of the playlist and increments of + 1 song
	for (int c = 1; c < i - 1; c++)
	{
		//goes next until the temporary index gets to a song node right before the chosen location of the list
		goToNext();
	}
	//attaches new songs prev pointer to the index pointer, which is the song node before the insert location
	(*s).setPrev(index);

	//attaches new songs next pointer to the index's next pointer, the song after the insert location
	(*s).setNext((*index).getNext());

	//attaches index's next's prev pointer to the new song, now the new song points forward to the song after insert location 
	(*(*index).getNext()).setPrev(s);

	//attaches index's next pointer to the new song, now the song before the insert location points forward to the new song 
	(*index).setNext(s);

	//accounts for the increase in size of the playlist after insertion
	size++;

	//resets the global index to the start of the list
	index = startIndex;
}

void DLL::insertAtBeg(songNode* s)
{
	//if the playlist doesnt exist, construct it with the new song and make size 1
	if (size == 0)
	{
		index = s;
		startIndex = s;
		endIndex = s;
		size++;
	}

	else
	{
		//set the new songs next to the 1st song of the list
		(*s).setNext(startIndex);

		//set the og 1st song's prev to the new song
		(*startIndex).setPrev(s);

		//redfine the head as the new node/song
		startIndex = s;

		//make index start at this new node
		index = s;

		//add 1 to size of playlist
		size++;
	}
}

void DLL::insertAtEnd(songNode* s)
{
	//set new songs prev to the last song of the list
	(*s).setPrev(endIndex);

	//set this og last song's next to the new song
	(*endIndex).setNext(s);

	//redefine the tail as the new song
	endIndex = s;

	//reset index to start
	index = startIndex;

	//increase size of playlist by 1
	size++;
}

void DLL::deleteAtBeg()
{
	
	if (size == 1)
	{
		//make index, start, and end null when deleting last song of playlist, and make size 0
		index = nullptr;
		startIndex = nullptr;
		endIndex = nullptr;
		size--;
	}
	else
	{
		//go to 2nd song
		goToNext();
		//set its prev to null
		(*index).setPrev(nullptr);
		//make new start the 2nd song
		startIndex = index;
		//reset index to this new start
		index = startIndex;
		//subtract size of list by 1
		size--;
	}

}

void DLL::deleteAtEnd()
{
	//go to end of playlist
	index = endIndex;
	//go to prev of last song
	goToPrev();
	//set the next of the 2nd last song to null
	(*index).setNext(nullptr);
	//define new end as the 2nd last song
	endIndex = index;
	//reset index to start
	index = startIndex;
	//subtract size by 1
	size--;
}

void DLL::deleteAtLocation(int i)
{
	//make for loop that begins at 1 and runs until counter reaches song right before the song that is to be deleted
	for (int c = 1; c < i - 1; c++)
	{
		//transverses to next song 1 by 1
		goToNext();
	}
	//makes temp index and points it to the song that is to be deleted
	songNode* s = index->getNext();

	//sets the prev of the song after the deleted song to the song before the deleted song
	(*(*s).getNext()).setPrev(index);

	//sets the next of the song before the deleted song to the song after the deleted song
	(*index).setNext((*s).getNext());
	//resets the index to the start
	index = startIndex;
	//subtracts size by 1
	size--;
}

string DLL::toString()
{
	//make counter to print out for each song entry
	int i = 1;
	//initialize playlist to print
	string list;
	//make index the start of list
	index = startIndex;
	//make loop that runs until every song in the playlist is printed
	while (index != nullptr)
	{
		//make list = the corresponding number, with the corresponding name and artist of each song, and add each song entry to it each iteration of the loop
		list += to_string(i) + ". " + index->getData() + "\n";
		//go to the next song
		index = index->getNext();
		//add to counter of playlist
		i++;
	}
	//reset index to start
	index = startIndex;
	//return from function with the playlist made
	return list;
}