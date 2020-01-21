#include <iostream>
using namespace std;

int main()
{
	int array[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
	int length = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < length; i++)
	{
		cout << "array[" << i << "]: " << array[i] << endl;
	}

	int number = 0;
	do
	{
		cout << "Enter a number between 1 and 9: ";
		cin >> number;
		if (cin.fail())
			cin.clear();
		cin.ignore(32767, '\n');

	} while (number < 1 || number > 9);
	for (int index = 0; index < length; ++index)
	{
		if (array[index] == number)
		{
			cout << "The number " << number << " has index " << index << "\n";
			break; 
		}
	}


	int students[] = { 73, 85, 84, 44, 78 };
	const int numStudents = sizeof(students) / sizeof(students[0]);
	int maxScore = 0;
	int maxIndex = 0;
	for (int person = 0; person < numStudents; ++person)
		if (students[person] > maxScore) {
			maxScore = students[person];
			maxIndex = person;
		}
	cout << "The best score was " << maxScore << ", index: " << maxIndex << endl;

	system("pause");
	return 0;
}