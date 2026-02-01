#pragma once
#include <iostream>
#include <string>
#include "DLL.h"
using namespace std;

class songNode
{
private:
	string songName;
	string artistName;
	//declare pointers which point to next and prev song nodes
	songNode* prevSong;
	songNode* nextSong;
public:
	songNode(string sn, string an);
	string getData();
	//setters take pointers and set the private pointer attrs to them
	void setNext(songNode* next);
	void setPrev(songNode* prev);
	//getters access nextSong and prevSong
	songNode* getNext();
	songNode* getPrev();
};
