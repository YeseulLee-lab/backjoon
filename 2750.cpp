#include <iostream>

using namespace std;

int N;
int a[10001] = { 0, };

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quick_sort(int a[], int left, int right)
{
	int pl = left;
	int pr = right;
	int p = a[(pl + pr) / 2];

	do
	{
		while (a[pl] < p) pl++;
		while (a[pr] > p) pr--;
		if (pl <= pr)
		{
			int temp = a[pl];
			a[pl] = a[pr];
			a[pr] = temp;

			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) quick_sort(a, left, pr);
	if (pl < right) quick_sort(a, pl, right);
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	quick_sort(a, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		cout << a[i] << '\n';
	}

	return 0;
}