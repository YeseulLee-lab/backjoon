#include <iostream>
#include <vector>
#define MAX 11

using namespace std;

int n;
int minimum = 100000000;
int maximum = -100000000;
int num[MAX];
int opernum[4];

void dfs(int result, int idx)
{
	if (idx == n)
	{
		if (result > maximum)
			maximum = result;
		if (result < minimum)
			minimum = result;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (opernum[i] > 0)
		{
			opernum[i] --;
			if (i == 0)
				dfs(result + num[idx], idx + 1);
			else if(i ==1)
				dfs(result - num[idx], idx + 1);
			else if(i ==2)
				dfs(result * num[idx], idx + 1);
			else 
				dfs(result / num[idx], idx + 1);
			opernum[i]++;
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> opernum[i];
	}

	dfs(num[0], 1);
	cout << maximum << "\n";
	cout << minimum;
}