#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>trees;
int n, m;
int result = 0;

void binary_search()
{
	int start = 0;
	int end = trees[n-1];

	while (start <= end)
	{
		long long int total = 0;
		int mid = (start + end) / 2;

		for (int i = 0; i < n; i++)
		{
			if (trees[i] > mid)
				total += trees[i] - mid;
		}

		if (total < m)
		{
			end = mid - 1;
		}
		else
		{
			result = mid;
			start = mid + 1;
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;
		trees.emplace_back(height);
	}

	sort(trees.begin(), trees.end());

	binary_search();

	cout << result;
}