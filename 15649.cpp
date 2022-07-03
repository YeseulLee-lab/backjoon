#include <iostream>
#include <vector>
#define MAX 8
using namespace std;

int arr[MAX];
bool sel[MAX];
int n, m;
vector<int> set;

void Print()
{
	for (int i = 0; i < set.size(); i++)
	{
		cout << set[i] << " ";
	}
	cout << "\n";
}

void Backtracking(int cnt)
{
	if (cnt == m)
	{
		Print();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (sel[i] == true)
			continue;
		sel[i] = true;
		set.push_back(arr[i]);
		Backtracking(cnt + 1);
		set.pop_back();
		sel[i] = false;
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	Backtracking(0);
}