# include <iostream>
using namespace std;

bool isEven(int x)
{
	return x % 2 == 0;
}

int main()
{
	cout << "Enter number: ";
	double a;
	cin >> a;
	if (isEven(a))
	{
		cout << a << " is even";
	}
	else
	{
		cout << a << " isn\'t even";
	}
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}