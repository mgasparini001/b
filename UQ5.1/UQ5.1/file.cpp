#include <iostream>
#include <vector>
using namespace std;
int main() {
	cout << "How many numbers would you like to input? ";
		int size;
		cin >> size;
		vector<int> nums;
		int num = 0;
		cout << "enter a number:\n";
		for (int i = 0; i < size; i++)
		{
			
			cin >> num;
			nums.push_back(num);
		}
		//make subarray
		int sub[size];
		//get sum of elements of the vector
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			for (int i2 = 0; i < size; i++) {
				
				cout << "size";
			}
			sum += nums[i];
			size--;
			cout << sum;
			
			


		}
		




		/*
		for (int i = 0; i < size; i++)
		{
			cout << "\n" << nums[i];
			
	
		}
		*/
	return 0;
}