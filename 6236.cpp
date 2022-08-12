#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<int> money;
int lo, hi = 0;

void binary_search()
{
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		int count = 1;
		int withdraw = mid;
		for (int i = 0; i < n; i++)
		{
			withdraw = withdraw - money[i];
			if (withdraw <= 0)
			{
				withdraw = mid - money[i];
				count++;
			}
		}
		if (count > m)
			lo = mid + 1;
		else
			hi = mid - 1;
		k = mid;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		money.emplace_back(temp);
		lo = max(lo, money[i]);
		hi += temp;
	}

	binary_search();
	cout << k;
}