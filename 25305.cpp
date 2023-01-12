#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, k;
	int x[1001] = { 0, };

	cin >> N >> k;

	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
	}

	sort(x, x + N, greater<>());

	cout << x[k - 1];

	return 0;
}