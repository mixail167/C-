#include <iostream>
#include <string>
#include <utility>
using namespace std;

void sort(string* array, int length)
{
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex;
		}
		swap(array[startIndex], array[smallestIndex]);
	}
}

int main()
{
	int number = 0;
	do{
		cout << "How many names would you like to enter? ";
		cin >> number;
		if (cin.fail())
			cin.clear();
		cin.ignore(32767, '\n');

	} while (number < 1);
	string *array = new string[number];
	for (int i = 0; i < number; i++)
	{
		cout << "Enter name #" << i + 1 << ": ";
		cin >> array[i];
		if (cin.fail())
		{
			cin.clear();
			i--;
		}
		cin.ignore(32767, '\n');
	}
	sort(array, number);
	cout << "Here is your sorted list :" << endl;
	for (int i = 0; i < number; i++)
	{
		cout << "Name #" << i + 1 << ": " << array[i] << endl;
	}

	delete[] array;
	array = nullptr;
	system("pause");
	return 0;
}