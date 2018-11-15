#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the initial height of the tower in meters: ";
	double a;
	cin >> a;
	cout << "Enter a second double value: ";
	double b;
	cin >> b;
	cout << "Enter one of the following: +, -, *, or /: ";
	char c;
	cin >> c;
	switch (c)
	{
	case '+':
		cout << a << " + " << b << " is " << a + b << endl;
		break;
	case '-':
		cout << a << " - " << b << " is " << a - b << endl;
		break;
	case '*':
		cout << a << " * " << b << " is " << a * b << endl;
		break;
	case '/':
		cout << a << " / " << b << " is " << a / b << endl;
		break;
	default:
		cout << "Error" << endl;
		break;
	}
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}