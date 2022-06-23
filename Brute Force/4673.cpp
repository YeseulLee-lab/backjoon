#include <iostream>
using namespace std;

int d(int num);

int main()
{
	bool isSelfnum[10001] = { false };

	for (int i = 1; i < 10001; i++)
	{
		if (d(i) <= 10001)
			isSelfnum[d(i)] = true;
	}

	for (int i = 1; i < 10001; i++)
	{
		if (!isSelfnum[i])
			cout << i << endl;
	}
}

int d(int num)
{
	int result = 0;
	result = num + num % 10000 / 1000 + num % 1000 / 100 + num % 100 / 10 + num % 10;

	return result;
}