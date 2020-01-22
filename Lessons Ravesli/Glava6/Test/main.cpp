#include <iostream>

enum ItemTypes
{
	ITEM_HEALTH_POTION,
	ITEM_TORCH,
	ITEM_ARROW,
	MAX_ITEMS
};

int countTotalItems(int* items)
{
	int totalItems = 0;
	for (int index = 0; index < MAX_ITEMS; ++index)
		totalItems += items[index];

	return totalItems;
}

struct Student
{
	std::string name;
	int grade;
};

void sortNames(Student* students, int length)
{
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		int largestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (students[currentIndex].grade > students[largestIndex].grade)
				largestIndex = currentIndex;
		}
		std::swap(students[startIndex], students[largestIndex]);
	}
}

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void printCString(const char* str)
{
	while (*str != '\0')
	{
		std::cout << *str;
		++str;
	}
	std::cout << std::endl;
}

int main()
{
	int items[MAX_ITEMS] = { 3, 6, 12 };
	std::cout << "The player has " << countTotalItems(items) << " items in total.\n";

	int numStudents = 0;
	do
	{
		std::cout << "How many students do you want to enter? ";
		std::cin >> numStudents;
	} while (numStudents <= 1);
	Student* students = new Student[numStudents];
	for (int index = 0; index < numStudents; ++index)
	{
		std::cout << "Enter name #" << index + 1 << ": ";
		std::cin >> students[index].name;
		std::cout << "Enter grade #" << index + 1 << ": ";
		std::cin >> students[index].grade;
	}
	sortNames(students, numStudents);
	for (int index = 0; index < numStudents; ++index)
		std::cout << students[index].name << " got a grade of " << students[index].grade << "\n";
	delete[] students;

	int x = 5;
	int y = 7;
	swap(x, y);

	if (x == 7 && y == 5)
		std::cout << "It works!" << std::endl;
	else
		std::cout << "It's broken!" << std::endl;

	printCString("Hello, world!");
	system("pause");
	return 0;
}