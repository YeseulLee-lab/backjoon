#include <iostream>
#include <vector>
#define MAX 8
using namespace std;

int arr[MAX];
bool sel[MAX];
int n, m;

void Print()
{
	for (int i = 0; i < n; i++)
	{
		if(sel[i] == true)
			cout << arr[i] << " ";
	}
	cout << "\n";
}

void DFS(int idx, int cnt)
{
	if (cnt == m)
	{
		Print();
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (sel[i] == true)
			continue;
		sel[i] = true;
		DFS(i, cnt + 1);
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

	DFS(0, 0);
}