#pragma once
#include <iostream>
#include <string>
#include "SongNode.h"
using namespace std;

class DLL {

private:

	int size;
	//index pointer is for globally navigating through the playlist
	songNode* index;
	//start is so that the start of the list is always accessible
	songNode* startIndex;
	//make end to always be able to access end of list
	songNode* endIndex;
public:

	DLL(songNode* first);
	songNode getCurrent();
	int getSize();
	//make setCurrent to make temporary index pointer, so you can navigate through list in the insert function defs
	void setCurrent(songNode* nS);
	void goToNext();
	void goToPrev();
	//inserting between two nodes requires a specified position on the list, and the new song node
	void insertAtLocation(int i, songNode* s);
	//other insert functions only require the new song node
	void insertAtBeg(songNode* s);
	void insertAtEnd(songNode* s);
	void deleteAtBeg();
	void deleteAtEnd();
	//deleting a node in between 2 others requires a specified position on the list
	void deleteAtLocation(int i);
	string toString();
};