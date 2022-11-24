#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bisearch(int n, int m, vector<int> &tree)
{
	int pl = 0;
	int pr = tree[n - 1];
	int result = 0;
	while (pl <= pr)
	{
		int mid = (pl + pr) / 2;
		long long int total = 0;
		for (int i = 0; i < tree.size(); i++)
		{
			if(tree[i] >= mid)
				total += tree[i] - mid;
		}
		if (total >= m)
		{
			if (result < mid)
				result = mid;
			pl = mid + 1;
		}
		else
			pr = mid - 1;
	}
	return result;
}

int main(void)
{
	int N, M;
	cin >> N >> M;

	vector<int> tree;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		tree.emplace_back(temp);
	}

	sort(tree.begin(), tree.end());

	cout << bisearch(N, M, tree);
}