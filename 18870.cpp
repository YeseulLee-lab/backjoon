#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1000001];

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> vec;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		vec.emplace_back(a[i]);
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < N; i++)
	{
		int idx = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();//ÀÎµ¦½º Ã£±â
		cout << idx << ' ';
	}
}