#include <iostream>
#include <vector>
#define MAX 20
using namespace std;

bool sel[MAX];
int stats[MAX][MAX];

int n;
int minimum = 99999;

void dfs(int idx, int cnt)
{
	vector<int> start;
	vector<int> link;

	int start_stat = 0;
	int link_stat = 0;

	if (cnt == n/2)
	{
		for (int i = 0; i < n; i++)
		{
			if (sel[i] == true)
				start.emplace_back(i);
			else
				link.emplace_back(i);
		}

		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				start_stat += stats[start[i]][start[j]];
				link_stat += stats[link[i]][link[j]];
			}
		}
		
		if (abs(start_stat - link_stat) < minimum)
			minimum = abs(start_stat - link_stat);

		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (sel[i] == true)
			continue;
		sel[i] = true;
		dfs(i, cnt + 1);
		sel[i] = false;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> stats[i][j];
		}
	}

	dfs(0, 0);
	cout << minimum;
}