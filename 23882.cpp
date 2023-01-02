#include <iostream>

using namespace std;

int a[10001] = { 0, };
void selection_sort(int N, int K, int a[])
{
	int cnt = 0;
	for (int i = N - 1; i > 0; i--)
	{
		int max = i;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[max])
				max = j;
		}
		if (max != i)
		{
			int temp = a[max];
			a[max] = a[i];
			a[i] = temp;
			if (++cnt == K)
			{
				for (int k = 0; k < N; k++)
				{
					cout << a[k] << " ";
				}
				return;
			}
		}
	}

	if(cnt<K)
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

	selection_sort(N, K, a);
}