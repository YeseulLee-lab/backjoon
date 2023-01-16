#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string>b)
{
	if (a.first == b.first)
		return false;
	return a.first < b.first;
}

int main(void)
{
	int N;
	cin >> N;

	vector<pair<int, string>> vec;
	for (int i = 0; i < N; i++)
	{
		int temp;
		string str;
		cin >> temp >> str;
		vec.push_back({ temp, str });
	}

	stable_sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].first << ' ' << vec[i].second << '\n';
	}
}