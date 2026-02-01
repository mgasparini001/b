#include <iostream>
#include <chrono>
using namespace std;

int recursivefib(int n) {


	if (n == 1 || n == 2) {
		n = 1;
		return n;
	}
	else {
		return recursivefib(n - 1) + recursivefib(n - 2);

		//fib(20) = fib(19) + fib(18)
		//fib(19) = fib(18) + fib(17)
		//...
		//fib(2) returns 1
		//fib(1) returns 1
		// fib(3) adds the returned values for fib(3-1) + fib(3-2) and returns 2
		// then all the following recursive cases add each result of the last 2 fib calls in this same way
		//ex: fib(4) returns fib(3) + fib(2) = 2 + 1 = 3
		//fib(5) returns fib(4) + fib(3) = 3 + 2 = 5 
	}
}


/*
get fib(1) by making x = 1 and fib(2) by y = 1 (the base cases)
then make foor loop that does fib(3)-fib(n)
make z the result, y the larger num to add, and x the smaller num to add
add the first 2 fib nums together to get 3rd fib num,
then keep adding each num's prior num to itself to get next fib num
*/
int loopfib(int n) {
	int x = 1;
	int y = 1;
	int z = 0;
	if (n == 1 || n == 2) {
		return x;
	}
	else {
		for (int i = 3; i <= n; i++) {
			//2 =  1  +  1
			z = x + y;

			//cout << z<<endl;
			//update smaller num(x) to 1(larger num)
			x = y;
			//update larger num(y) to 2(the sum of the last 2 nums)
			y = z;


			//2nd iteration:

			//3 = 1 + 2
			//update smaller num = 2
			//update larger num = 3


			//3rd:

			//5 = 2 + 3
			//update smaller num = 3
			//update larger num = 5
			
			//and so on until last iteration
			//ex: fib(20) = 6765 = 4181 + 2584

		}


		return z;

	}
	
	

	
		
		
	}

int main() {
 
 // Start measuring time
 auto begin = std::chrono::high_resolution_clock::now();

 
 //store the output of the function in var to print out
  //cout << "40th fibonnaci num is ";
 int result = recursivefib(40);

 // Stop measuring time and calculate the elapsed time
 auto end = std::chrono::high_resolution_clock::now();
 auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);


 printf("Recursion Result: %d\n", result);

 printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);

 ////////////////////////////////////////////////////////////////////////////////////

 // Start measuring time
 auto begin2 = std::chrono::high_resolution_clock::now();
 
	 //store the output of the function in var to print out
  //cout << "40th fibonnaci num is ";
	 int result2 = loopfib(40);

 // Stop measuring time and calculate the elapsed time
 auto end2 = std::chrono::high_resolution_clock::now();
 auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);


 printf("Loop Result: %d\n", result2);

 printf("Time measured: %.3f seconds.\n", elapsed2.count() * 1e-9);
	return 0;
}