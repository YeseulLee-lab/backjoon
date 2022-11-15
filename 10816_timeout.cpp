#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bisearch(int n, vector<int> &a)
{
	int pl = 0;
	int pr = n - 1;
	int key;
	int cnt = 0;
	cin >> key;

	while (pl <= pr)
	{
		int pc = (pl + pr) / 2;
		if (a[pc] == key)
		{
			cnt++;
			while (pc > pl && a[pc - 1] == key)
			{
				pc--;
			}
			while (pc < pr && a[pc + 1] == key)
			{
				pc++;
				cnt++;
			}
			return cnt;
			
		}
		else if (a[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	}

	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	vector<int> a;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		a.emplace_back(temp);
	}
	sort(a.begin(), a.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cout << bisearch(N, a) << " ";
	}

	return 0;
}