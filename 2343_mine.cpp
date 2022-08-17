#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> minutes;
int result;
int lo, hi = 0;

void binary_search()
{
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		int count = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum + minutes[i] > mid)
			{
				sum = 0;
				count++;
			}
			sum += minutes[i];
		}
		if (sum != 0)
			count++;

		if (count > m)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	result = lo;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		minutes.emplace_back(temp);
		lo = max(lo, minutes[i]);
		hi += temp;
	}
	
	binary_search();

	cout << result;
}