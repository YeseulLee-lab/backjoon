#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bisearch(int n, vector<int> &a)
{
	int x;
	int pl = 0;
	int pr = n - 1;

	scanf("%d", &x);

	while (pl <= pr)
	{
		int pc = (pl + pr) / 2;
		if (a[pc] == x)
			return 1;
		else if (a[pc] < x)
			pl = pc + 1;
		else
			pr = pc - 1;
	}
	return 0;
}

int main(void)
{
	int N, M;
	vector<int> a;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		a.emplace_back(temp);
	}
	sort(a.begin(), a.end());

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		printf("%d ", bisearch(N, a));
	}
}