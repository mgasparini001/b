#include <iostream>
#include <vector>
using namespace std;
//make void functionm and refer to vector in main() to modify and size to use as param for loop
void doublee(vector<int>& nums, int&size) {
	//double every element in vector
	for (int i = 0; i < size; i++)
	{
		nums[i] *= 2;
	}



}
int main() {
	vector<int> nums;
	cout << "enter nums to double: (-1 to stop) ";
	//intialize num so you can cin it, initialize size so you can count how many nums there are and use it in double function
		int num;
		int size = 0;
		//make while loop that loops inputting nums
		while (cin >> num) {
			//add each one to vector
			nums.push_back(num);
			cout << "\n";
			//use -1 to break
			if (num == -1) {
				break;
			}
			
			size++;
	}
		//call function
		doublee(nums, size);
		//cout all doubled nums
		for (int i = 0; i < size; i++)
		{
			cout << nums[i] << " ";
			}


	return 0;
}