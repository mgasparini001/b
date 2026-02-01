#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int nums[5][5];

	//intialize vars
	int num;
	int minrow = 0;
	int maxrow = 0;
	int mincolumn = 0;
	int maxcolumn = 0;
	int min = 0;
	int max = 0;
	//make outer loop for each row that loops every row index, from [0][4] to [4][4]
	for (int row = 0; row < 5; row++)
	{//inner for each column
		for (int column = 0; column < 5; column++)
		{
			cout << "\nenter a number :";
			cin >> num;
			//intially define min and max based off first input so they dont get updated each loop and end up == the num every time
			if (column == 0 && row == 0)
			{
				min = num;
				 max = num;
			}
			//store each input into every column index, from [0][0] to [0][4], 
			// then to [1][4], etc until array is complete
			nums[row][column] = num;

			//check if the entered number is less than the last num
			if (num < min) {
				//if less, update min to it and locate its row and column
				min = num;
				minrow = row + 1;
				mincolumn = column + 1;
				
			}
			//same here but reversed
			if (num > max) {
				max = num;
				maxrow = row + 1;
				maxcolumn = column + 1;
			}

		}
	}


	//make loop to print each num out
	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 5; column++)
		{
			cout << nums[row][column] << " ";//space for each column


		}
		cout << "\n";//\n for each row
	}
	//print min/max and locations
	cout << "min: " << min << ", found in row " << minrow << " column " << mincolumn;
	cout << "\nmax: " << max << ", found in row " << maxrow << " column " << maxcolumn;

	return 0;
}