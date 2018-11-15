#include <iostream>
#include "constants.h"
using namespace std;
using namespace myConstants;

float getHeight(float h, int second)
{
	return h - g*second*second*1.0f / 2;
}

int main()
{
	cout << "Enter the initial height of the tower in meters: ";
	float initH;
	cin >> initH;
	float b;
	int i = 0;
	while (true)
	{
		b = getHeight(initH, i);
		if (b > 0)
		{
			cout << "At " << i << " seconds, the ball is at height: " << b << " meters" << endl;
		}
		else
		{
			cout << "At " << i << " the ball is on the ground" << endl;
			break;
		}
		i++;
	}
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}