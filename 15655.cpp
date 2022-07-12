#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

int n, m;
vector<int> nums;
bool sel[MAX];
vector<int> V;

void dfs(int cnt, int idx)
{
	if (cnt == m)
	{
		for (int i = 0; i < nums.size(); i++)
		{	
			if(sel[i] == true)
				cout << nums[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (sel[i] == true)
			continue;
		sel[i] = true;
		V.emplace_back(nums[i]);
		dfs(cnt + 1, i);
		V.pop_back();
		sel[i] = false;
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nums.emplace_back(num);
	}

	sort(nums.begin(), nums.end());

	dfs(0, 0);
}