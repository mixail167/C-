#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� �����"<< endl;
	cin.clear();
	//cin.ignore(32767, '\n');
	cin.get();
	return 0;
}