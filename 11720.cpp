#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int num = 0;
	int sum = 0;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int temp;
		scanf_s("%1d", &temp);
		sum += temp;
	}

	cout << sum;

	return 0;
}