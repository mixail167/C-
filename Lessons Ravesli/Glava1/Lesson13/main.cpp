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
	cout << "������� ����� �����: ";
	cin >> a;
	cout << "��������� �����: " << doubleNumber(a);
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}