#include <iostream>
#include <string>
using namespace std;

enum class Animal
{
	PIG, CHICKEN, GOAT, CAT, DOG, OSTRICH
};

string getAnimalName(Animal animal)
{
	switch (animal)
	{
	case Animal::PIG:
		return "PIG";
	case Animal::CHICKEN:
		return "CHICKEN";
	case Animal::GOAT:
		return "GOAT";
	case Animal::CAT:
		return "CAT";
	case Animal::DOG:
		return "DOG";
	case Animal::OSTRICH:
		return "OSTRICH";
	default:
		return "Unknown animal";
	}
}

void printNumberOfLegs(Animal animal)
{
	cout << "A " << getAnimalName(animal) << " has ";
	switch (animal)
	{
	case Animal::CHICKEN:
	case Animal::OSTRICH:
		cout << "2";
		break;
	case Animal::PIG:
	case Animal::GOAT:
	case Animal::CAT:
	case Animal::DOG:
		cout << "4";
		break;
	default:
		cout << "unknown count";
		break;
	}
	cout << " legs." << endl;
}

int calculate(int x, int y, char op)
{
	switch (op)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		if (y == 0)
		{
			cout << "Error: Devide by Zero" << endl;
			return 0;
		}
		return x / y;
	case '%':
		return x % y;
	default:
		cout << "Error: Unknown operand" << endl;
		return 0;
	}
}

int main()
{
	cout << "5%2=" << calculate(5, 2, '%') << endl;
	printNumberOfLegs(Animal::CAT);
	printNumberOfLegs(Animal::CHICKEN);
	cin.clear();
	cin.get();
	return 0;
}