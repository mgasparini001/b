#include "Header.h"
#include <cmath>
using namespace std;
//declare and define exit message by using "~nameofclass()"
	rectangle::~rectangle() {
		cout << "Thanks for using rectangle!";
	}
	
	//define the setters: assign the inputted values into the defualt private values of length and width if they meet the range needed

	void rectangle::setwidth(double w) {
		if (/*floor(w) != ceil(w) &&*/ w > 0.0 && w < 20.0) {
			width = w;
		}
		else {
			//invalid speed, set to default
			cout << "The width must be a double between 0 and 20\n";
			width = 1;
		}
		

	}
	void rectangle::setlength(double l) {
		
		if ( l > 0.0 && l < 20.0) { 
			length = l;
		}
		else {
		
			cout << "The length must be a double between 0 and 20\n";
			length = 1;
		}
	}
	//define getters by just returning the length and width members from private
	double rectangle::getlength() {
		
		return length;

	}
	double rectangle::getwidth() {
		

		return width;
	}
	//define area and perimeter by returning their formulas with
	// the length and width, which were obtained by the getters, plugged in
	double rectangle::area() {
		return length * width;
		

	}

	double rectangle::perimeter() {
		return (2 * length) + (2 * width);
		
	}
	//define constructor by using the name of the class, having the variables that go in be 
	//length and width, making new variables for them, and setting the variables
	rectangle::rectangle(double l, double w) {
		
		setwidth(w); //call the setter functions 
		//to make sure the l and w is in the specified range
		setlength(l);
		cout << "found the perimeter and area of the rectangle!\n";
	}
		