#include <iostream>
#include <vector>
#define MAX 8
using namespace std;

int n, m;
int arr[MAX];
vector<int> nums;

void dfs(int cnt, int idx)
{
	if (cnt == m)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++)
	{
		nums.emplace_back(arr[i]);	
		dfs(cnt + 1, i);
		nums.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	dfs(0, 0);
}