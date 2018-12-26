#include <iostream>
using namespace std;

int main()
{
	char c = 'a';
	while (c <= 'z')
	{
		cout << c << " " << static_cast<int>(c) << endl;
		c++;
	}
	int a = 5;
	while (a >= 1)
	{
		int b = a;
		while (b >= 1)
		{
			cout << b << " ";
			b--;
		}
		cout << endl;
		a--;
	}
	a = 1;
	while (a <= 5)
	{
		int b = 5;
		while (b >= 1)
		{
			if (b <= a)
			{
				cout << b << " ";
			}
			else
			{
				cout << "  ";
			}
			b--;
		}
		cout << endl;
		a++;
	}
	cin.clear();
	cin.get();
	return 0;
}