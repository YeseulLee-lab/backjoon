#include <iostream>
#include <algorithm>

using namespace std;
int a[10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N, M;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> M;
		a[M] += 1;
	}

	for (int i = 0; i < 10001; i++)
	{
		if (a[i] == 0)
			continue;
		else
		{
			for (int j = 0; j < a[i]; j++)
				cout << i << '\n';
		}
	}

	return 0;
}