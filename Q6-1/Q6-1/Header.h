#pragma once
#include <iostream>
#include <string>
#include <random>
#ifndef rectangle_h 
#define rectangle_h

using namespace std;

//declare class
class rectangle {
	//make attributes (length and width) private it so they can 
	// only be accessed by the functions of the class (security)
private:
	double length;
	double width;
	

	//declare all functions, make all the functions public

public:
	//declare setters and getters
	double getlength();
		
	
	
	void setlength(double l);
		
	
	double getwidth();
		
	

	void setwidth(double w);
	
	

	double perimeter();
		
	
	double area();
		


	//intialize constructor, which is what allows the class attributes to be modified, with initial values of 1
	rectangle(double l = 1, double w = 1);
		
	
	



	
	~rectangle();




};
#endif // !rectangle_h
