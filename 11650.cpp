#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int N;
	vector<pair<int, int>> vec;

	cin >> N;

	for (int i = 0; i < N; i++)
	{

		int temp1, temp2;
		cin >> temp1 >> temp2;
		vec.push_back({ temp1, temp2 });
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].first << ' ' << vec[i].second << '\n';
	}

	return 0;
}