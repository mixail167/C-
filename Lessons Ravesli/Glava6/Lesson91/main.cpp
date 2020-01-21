#include <iostream>
#include <string>
using namespace std;

int main()
{
	string array[] = { "Sasha", "Ivan", "John", "Orlando", "Leonardo", "Nina", "Anton", "Molly" };
	string name;
	cout << "Enter Name: ";
	cin >> name;
	cin.ignore(32767, '\n');
	bool found = false;
	for each (auto var in array)
	{
		if (var == name)
		{
			found = true;
			break;
		}
	}
	if (found)
		cout << name << " found" << endl;
	else
		cout << name << " not found" << endl;
	system("pause");
	return 0;
}
