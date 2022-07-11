#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

int n, m;
vector<int> arr;
bool sel[MAX];
vector<int> nums;

void dfs(int cnt)
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

	for (int i = 0; i < n; i++)
	{
		if (sel[i] == true)
			continue;
		sel[i] = true;
		nums.emplace_back(arr[i]);	
		dfs(cnt + 1);
		nums.pop_back();
		sel[i] = false;
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin>> num;
		arr.emplace_back(num);
	}
	sort(arr.begin(), arr.end());
	dfs(0);
}