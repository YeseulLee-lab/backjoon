#include <iostream>
#include <vector>
#define MAX 7
using namespace std;

int n, m;
int num[MAX];

vector<int> V;

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < V.size(); i++)
		{
			cout << V[i] <<" ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		V.emplace_back(num[i]);
		dfs(cnt + 1);
		V.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		num[i] = i + 1;
	}

	dfs(0);
}