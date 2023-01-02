#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;

	int arr[10005] = { 0, };

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int cnt = 0;
	for (int i = N - 1; i > 0; i--)
	{
		int max = i;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[max])
			{
				max = j;
			}
		}
		if (max != i)
		{
			int temp = arr[max];
			arr[max] = arr[i];
			arr[i] = temp;

			if (++cnt == K)
			{
				cout << arr[max] << " " << arr[i];
				return 0;
			}
		}
	}

	if (cnt < K)
	{
		cout << -1;
		return 0;
	}
}