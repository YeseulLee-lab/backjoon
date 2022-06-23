#include <iostream>
using namespace std;

int hansu(int num);

int main(void)
{
	int num = 0;
	int count = 0;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		count += hansu(i);
	}

	cout << count << endl;

	return 0;
}

int hansu(int num)
{
	int hundred, ten, one = 0;

	hundred = num / 100;
	ten = num % 100 / 10;
	one = num % 10;

	if ((hundred - ten) == (ten - one) || num < 100)
		return 1;
	else
		return 0;
}