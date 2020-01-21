#include <iostream>
using namespace std;

namespace Animals
{
	enum Animals
	{
		CHICKEN,
		LION,
		GIRAFFE,
		ELEPHANT,
		DUCK,
		SNAKE,
		MAX_ANIMALS
	};
}

int main()
{
	double temperatures[365] = { 0.0 };
	int legs[Animals::MAX_ANIMALS] = { 2, 4, 4, 4, 2, 0 };

	cout << "An elephant has " << legs[Animals::ELEPHANT] << " legs." << endl;
	int length = sizeof(temperatures) / sizeof(temperatures[0]);
	for (int i = 0; i < length; i++)
	{
		cout << "Day " << i + 1 << ": " << temperatures[i] << endl;
	}
	system("pause");
	return 0;
}