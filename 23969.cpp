#include <iostream>

using namespace std;

int a[10001] = { 0, };

void bubble_sort(int N, int K)
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
				if (cnt == K)
				{
					for (int k = 0; k < N; k++)
					{
						cout << a[k] << " ";
					}
					return;
				}
			}
		}
	}

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

	bubble_sort(N, K);
	return 0;
}