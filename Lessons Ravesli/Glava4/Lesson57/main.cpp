# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� ��� ������ ���: ";
	string fullName;
	getline(cin, fullName);
	int len = fullName.length();
	if (len > 0)
	{
		cout << "������� ���� �������: ";
		int age;
		cin >> age;
		cout << setprecision(3) << static_cast<float>(age) / len << " ���" << endl;
	}
	else
	{
		cout << "������������ ����";
	}
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}