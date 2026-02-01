#pragma once
#include <iostream>
#include <string>
#include <random>
#ifndef rectangle_h
#define rectangle_h

using namespace std;


class rectangle {
private:

	int length{ 1 };
	int width{ 1 };
	double perimeter;
	double area;


public:  void get(double length, double width);
	  void set(double length, double width);
	void getperimeter(double length, double width);
	  void getarea(double length, double width);
	  rectangle(double length, double width);
	
	  rectangle() {}
	  ~rectangle();

};
#endif // !rectangle_h
int main() {



	return 0;
}