# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

struct Advertising
{
	int adsShown;
	double clickThroughRatePercentage;
	double averageEarningsPerClick;
};

struct Drob
{
	int chislitel;
	int znamenatel;
};

void multiply(Drob d1, Drob d2)
{
	cout << static_cast<float>(d1.chislitel* d2.chislitel) /
		(d1.znamenatel* d2.znamenatel);
}

void printAdvertising(Advertising ad)
{
	cout << "Number of ads shown: " << ad.adsShown << endl;
	cout << "Click through rate: " << ad.clickThroughRatePercentage << endl;
	cout << "Average earnings per click: $" << ad.averageEarningsPerClick << endl;
	cout << "Total Earnings: $" <<
		(ad.adsShown * ad.clickThroughRatePercentage / 100 * ad.averageEarningsPerClick) << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Advertising ad;
	cout << "How many ads were shown today? ";
	cin >> ad.adsShown;
	cout << "What percentage of users clicked on the ads? ";
	cin >> ad.clickThroughRatePercentage;
	cout << "What was the average earnings per click? ";
	cin >> ad.averageEarningsPerClick;
	printAdvertising(ad);
	Drob d1;
	cout << "Input the first chislitel: ";
	cin >> d1.chislitel;
	cout << "Input the first znamenatel: ";
	cin >> d1.znamenatel;
	Drob d2;
	cout << "Input the second chislitel: ";
	cin >> d2.chislitel;
	cout << "Input the second znamenatel: ";
	cin >> d2.znamenatel;
	multiply(d1, d2);
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}