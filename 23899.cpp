#include <iostream>

using namespace std;

int a[10001] = { 0, };
int b[10001] = { 0, };

void selection_sort(int N)
{
	for (int i = N - 1; i > 0; i--)
	{
		int max = i;
		int cnt = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[max] < a[j])
				max = j;
		}
		if (max != i)
		{
			int temp = a[max];
			a[max] = a[i];
			a[i] = temp;
			for (int k = 0; k < N; k++)
			{
				if (a[k] == b[k])
					cnt++;
			}

			if (cnt == N)
			{
				cout << 1;
				return;
			}
		}
	}
	cout << 0;
}

int main(void)
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> b[i];
	}

	selection_sort(N);
}