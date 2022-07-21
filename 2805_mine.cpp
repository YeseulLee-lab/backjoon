#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> trees;
int result = 0;

void binary_search()
{
	int start = 0;
	int end = trees[n - 1];

	while (start <= end)
	{
		int mid = (end + start) / 2;
		long long int total = 0;
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
	binary_search();
	cout << result;
}