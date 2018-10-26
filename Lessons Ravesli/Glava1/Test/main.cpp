#include <iostream>
#include "io.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	writeAnswer(readNumber() + readNumber());
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}