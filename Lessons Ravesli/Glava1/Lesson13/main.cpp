#include <iostream>
using namespace std;

int doubleNumber(int a)
{
	return 2 * a;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "¬ведите целое число: ";
	cin >> a;
	cout << "”двоенное число: " << doubleNumber(a);
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}