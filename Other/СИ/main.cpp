#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char digit(int num)
{
	switch (num) {
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';
	default: return '0';
	}
}

char* dectox_int(unsigned long int a, unsigned int p)
{
	char s[50];
	int i = 0;
	while (a >= p)
	{
		s[i] = digit(a % p);
		a /= p;
		i++;
	}
	s[i] = digit(a);
	s[i + 1] = 0;
	return _strrev(s);
}

unsigned long int x_inttodec(const char* a, int p)
{
	unsigned long int sum = 0;
	if (a)
	{
		size_t n = strlen(a);
		for (size_t i = 0; i < n; i++)
		{
			int d = int(a[i]) - '0';
			sum += (unsigned long int)pow(p, n - i - 1) * d;
		}
	}
	return sum;
}

int main()
{
	const char a[10][50] = { "0", "1", "1234567", "000100", "177777", "200000", "7", "0020", "37777777777", "10000001" };
	unsigned long int b[10];
	char c[10][50];
	for (size_t i = 0; i < 10; i++)
	{
		b[i] = x_inttodec((char*)a[i], 8);
		strcpy(c[i], dectox_int(b[i], 8));
		cout << a[i] << " " << b[i] << " " << c[i] << endl;
	}
	system("pause");
	return 0;
}