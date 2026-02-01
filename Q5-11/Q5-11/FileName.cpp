#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<double> myVector = { 1,2,3,4,5,6,7,8 };

	for (double element : myVector)

	{

		element = 3 * element;
		cout << element << endl;
	}
	/*
	for (double element : myVector)

	{

		cout << element << endl;

	}
	*/

	return 0;
}




//What went wrong :the element variables are seperately defined in the 2 for loops, so the original elements are printed in the 
// 2nd loop since the ones multipolied by 3 dont carry over

//One fix(want an explanation of changes, not just code): put the cout statement right after the multiplication line in the same loop, 
// so that it actually couts the same variable that it multiplies