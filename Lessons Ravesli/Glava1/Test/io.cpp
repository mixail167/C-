#include <iostream>
using namespace std;

int readNumber()
{
	int a;
	cout << "Введите число: ";
	cin >> a;
	return a;
}

void writeAnswer(int a)
{
	cout << "Ваше число: " << a << endl;
}