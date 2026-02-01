/*

1. 1.33, therefore the limit of a(n) as n approaches infinity is 1.33 
2. No, always 1.33

*/

#include <iostream>
using namespace std;

//takes in total recursion number ogn, recursion counter n, a(1) m, and performs recursive formula
 double a(double n, double m, double ogn) {
	 //when a(1) = 2
	//a(2) = 0.25(a(1)) + 1 = 1.5
	//a(3) = 0.25(a(2)) + 1 = 1.375
	//a(4) =0.25(a(3)) + 1 = 1.34375
	 double value;
	//base case a(1), returns the result the user enters
	if (n == 1) {
		
		return m;
	}

	//recursive cases
	else {
		//make counter that starts == num of results,then decreases to 1,
		// and then increases back to the total num
		//it keeps track of n, the recursion counter
		int i = n;

		//store value of each computation using recursion
		value = (0.25 * (a(n - 1, m, ogn))) + 1;

		//check for when counter reaches num of values user wanted, 
		// meaning when all values have been calculated
		if (i == ogn) {

			//prints out the num the last value is at
			cout << "a(" << i << ")" << ": ";
			//doesnt print the last value itself since main does that already
			//simply ends the function returning with that value
			return value;

	}
		//when all the values havent been calculated,
		// print out and return each value back to the next recursion
		cout << "a(" << i << ")"<< ": " << value << endl;
		return value;
		
			
	}
	
}


int main() {
	//make while loop so user can use the sequence as many times as theyd like
	while (true) {
		cout << "enter the 1st result of the recursive sequence 'a(n) = 1/4a(n-1) + 1', a(1): ";
		double m;
		cin >> m;
		double n;
		cout << "\nenter how many times you want the sequence to recur: ";

		cin >> n;
	//print out base case
		cout << "a(1): " << m << endl;
		//call recursive sequence
		cout << a(n, m, n);
		//allow a way to stop the program
		cout <<  "\nenter 0 to stop: ";
		int answer;
		cin >> answer;
		if (answer == 0) {
			break;
		}
		
	}
	return 0;
	}
	


	



	
