# include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� �����: ";
	int a;
	cin >> a;
	cout << "������� ������� �����: ";
	int b;
	cin >> b;
	if (a > b)
	{
		cout << "������ ��������" << endl;
		int tmp = a;
		a = b;
		b = tmp;
	}
	cout << "������� �����: " << a << endl;
	cout << "������� �����: " << b << endl;
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}