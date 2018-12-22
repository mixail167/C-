# include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите число: ";
	int a;
	cin >> a;
	cout << "Введите большее число: ";
	int b;
	cin >> b;
	if (a > b)
	{
		cout << "Меняем значения" << endl;
		int tmp = a;
		a = b;
		b = tmp;
	}
	cout << "Меньшее число: " << a << endl;
	cout << "Большее число: " << b << endl;
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}