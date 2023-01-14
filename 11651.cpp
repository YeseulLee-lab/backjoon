#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector <pair< int, int >> vec;

	for (int i = 0; i < N; i++)
	{
		int temp, temp1;
		cin >> temp >> temp1;
		vec.push_back({ temp1, temp });
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].second << ' ' << vec[i].first << '\n';
	}

	return 0;
}