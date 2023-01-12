#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int a[5] = { 0, };
	int mid, avg;
	int total = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		total += a[i];
	}

	sort(a, a + 5);

	mid = a[2];

	avg = total / 5;

	cout << avg << '\n' << mid;

	return 0;
}