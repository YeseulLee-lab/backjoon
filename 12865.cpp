#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack_01(int n, int k, vector<int> v, vector<int> w)
{
	vector<vector<int>> DP(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		int currentW = w[i - 1];
		int currentV = v[i - 1];

		for (int totalW = 1; totalW <= k; totalW++)
		{
			if (totalW < currentW)
				DP[i][totalW] = DP[i - 1][totalW];
			else
				DP[i][totalW] = max(DP[i - 1][totalW], DP[i - 1][totalW - currentW] + currentV);
		}
	}

	return DP[n][k];
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> v(n), w(n);

	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
		cin >> v[i];
	}

	int result = knapsack_01(n, k, v, w);

	cout << result << endl;
}
