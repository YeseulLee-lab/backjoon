#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	vector<int> a;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		a.emplace_back(temp);
	}
	sort(a.begin(), a.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int key;
		cin >> key;
		auto l = lower_bound(a.begin(), a.end(), key);
		auto r = upper_bound(a.begin(), a.end(), key);
		cout << r - l << " ";
	}

	return 0;
}