# include <iostream>
using namespace std;

int printandDecrementBit(int x, int pow)
{
	if (x >= pow)
	{
		cout << "1";
		return x - pow;
	}
	else
	{
		cout << "0";
		return x;
	}		
}

int main()
{
	cout << "Enter number: ";
	int x;
	cin >> x;
	x = printandDecrementBit(x, 128);
	x = printandDecrementBit(x, 64);
	x = printandDecrementBit(x, 32);
	x = printandDecrementBit(x, 16);
	x = printandDecrementBit(x, 8);
	x = printandDecrementBit(x, 4);
	x = printandDecrementBit(x, 2);
	x = printandDecrementBit(x, 1);
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}