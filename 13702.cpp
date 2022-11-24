#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Bisearch(int n, int k, vector<long long int> &vec)
{
	long long int pl = 1;
	long long int pr = vec[n - 1];
	long long int result = 0;
	while (pl <= pr)
	{
		long long int mid = (pl + pr) / 2;
		long long int total = 0;
		for (int i = 0; i < n; i++)
		{
			total += vec[i] / mid;
		}
		if (total >= k)
		{
			if(result < mid)
				result = mid;
			pl = mid + 1;
		}
		else
			pr = mid - 1;
	}
	return result;
}

int main(void)
{
	long long int N, K;
	cin >> N >> K;

	vector<long long int> mak;
	for (int i = 0; i < N; i++)
	{
		long long int temp;
		cin >> temp;
		mak.emplace_back(temp);
	}

	sort(mak.begin(), mak.end());

	cout << Bisearch(N, K, mak);
}