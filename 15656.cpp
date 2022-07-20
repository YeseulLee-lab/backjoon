#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 7
using namespace std;

int n, m;
vector<int> arr;
vector<int> vec;

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		vec.emplace_back(arr[i]);
		dfs(cnt + 1);
		vec.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.emplace_back(temp);
	}

	sort(arr.begin(), arr.end());

	dfs(0);
}