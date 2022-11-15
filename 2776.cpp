#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bisearch(int n, vector<int> &memo)
{
	int pl = 0;
	int pr = n - 1;
	int key;

	cin >> key;

	while (pl <= pr)
	{
		int pc = (pl + pr) / 2;
		if (memo[pc] == key)
			return 1;
		else if (memo[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	}

	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M;

	cin >> T;

	while (T--)
	{
		vector<int> memo;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			memo.emplace_back(temp);
		}
		sort(memo.begin(), memo.end());

		cin >> M;

		for (int i = 0; i < M; i++)
		{
			cout << bisearch(N, memo) << "\n";
		}
	}
	return 0;
}