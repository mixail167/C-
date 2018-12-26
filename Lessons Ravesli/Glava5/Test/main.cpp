#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX)+1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();
	char c;
	do
	{
		cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is." << endl;
		int number = getRandomNumber(1, 100);
		int i = 1;
		int n;
		while (i <= 7)
		{
			cout << "Guess #" << i << ": ";			
			cin >> n;
			if (n == number)
			{
				break;
			}
			else if (n > number)
			{
				cout << "Your guess is too high." << endl;
			}
			else
			{
				cout << "Your guess is too low." << endl;
			}
			i++;
		}
		if (n != number)
		{
			cout << "Sorry, you lose. The correct number was " << number << "." << endl;
		}
		else
		{
			cout << "Correct! You win!" << endl;
		}
		while (true)
		{
			cout << "Would you like to play again (y/n)? ";
			cin.clear();
			cin.ignore(32767, '\n');
			c = tolower(cin.get());
			if (c == 'n' || c == 'y')
			{
				break;
			}
		}
	} while (c != 'n');
	cout << "Thank you for playing.";
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}