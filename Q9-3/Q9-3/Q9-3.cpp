#include <iostream>
using namespace std;

//calculates and prints collatz sequence from starting n user gives
int C(int n) {
	//base case, returns 1 and stops recursion
	if (n == 1) {
		return n;
	}

	//check for when the num is even and more than 1
		if (n % 2 == 0) {
			//divide by 2
			n = (n / 2);
			//print resulting num
			cout << n << endl;
			//repeats function for new result until num = 1
			return C(n);
		}
		//same thing as above but for odd nums
		else if (n % 2 != 0) {
			//computation for odd nums
			n = (3 * n) + 1;
			
			cout << n << endl;
			//recurses for new result until reaching base case
			return C(n);
		}

	
}

int main() {
	//make loop so user can use collatz sequence as many times as theyd like
	while (true) {
		cout << "give positive integer: ";
		int n;
		cin >> n;
		
		C(n);
		cout << "type 0 to stop: ";
		int answer;
		cin >> answer;
		if (answer == 0) {
			break;
		}
	}
	
	
}
