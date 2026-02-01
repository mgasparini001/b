#include "SongNode.h"
#include <iostream>
#include <string>
using namespace std;

songNode::songNode(string sn, string an)
{
	
	songName = sn;
	artistName = an;
	//initialize next and prev pointers as null before theyre constructed
	prevSong = nullptr;
	nextSong = nullptr;
}

string songNode::getData()
{
	//access each song nodes info so that you can print each song out
	return songName + " by " + artistName;
}

void songNode::setNext(songNode* next)
{
	//take pointer and set the nextSong pointer to them
	nextSong = next;
}

void songNode::setPrev(songNode* prev)
{
	//take pointer and set the prevSong pointer to them
	prevSong = prev;
}

songNode* songNode::getNext()
{
	//access next pointer from songnode class
	return nextSong;
}

songNode* songNode::getPrev()
{
	//access previous pointer from songnode class
	return prevSong;
}
