#include <iostream>
#include "Header.h"
using namespace std;
//make run function to let user use the class
void run() {
	double l, w; //u can initialize multiple vars in one line
	cout << "Enter length for rectangle: ";
	cin >> l;
	cout << "Enter width for rectangle: ";
	cin >> w;
	//assign new name for the class and make the params l and w
	rectangle rect(l, w);
	//use classname.function() to get perimeter and area the functions being any function defined in the class
	cout << "the perimeter is: " << rect.perimeter()
		<< " and the area is: " << rect.area() << endl;
	
}

//make test cases with the constructor and use the member functions on them
//call run function in main and execute the class
	int main() {
		rectangle r1(7, 8);
		rectangle r2(4, 12);
		rectangle r3(23, 59);
		cout << "rectangle 1 perimeter is: " << r1.perimeter() << endl;
		cout << "rectangle 2 perimeter is: " << r2.perimeter() << endl;
		cout << "rectangle 3 perimeter is: " << r3.perimeter() << endl;
		cout << "rectangle 1 area is: " << r1.area() << endl;
		cout << "rectangle 2 area is: " << r2.area() << endl;
		cout << "rectangle 3 area is: " << r3.area() << endl;
		run();
		return 0;
	}




