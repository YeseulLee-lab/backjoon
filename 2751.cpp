#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	sort(a, a + N);

	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\n';
	}

	return 0;
}