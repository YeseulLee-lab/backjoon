#include <iostream>

using namespace std;

int a[100001] = { 0, };

void Bubble_Sort(int N, int K)
{
	int cnt = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				cnt++;
			}

			if (cnt == K)
			{
				cout << a[j] << " " << a[j + 1];
				return;
			}
		}
	}

	if (cnt < K)
		cout << -1;
}

int main(void)
{
	int N, K;
	
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	Bubble_Sort(N, K);

	return 0;
}