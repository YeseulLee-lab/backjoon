#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int n, m, start;
int map[MAX][MAX];
bool visited[MAX];

void dfs(int start)
{
	visited[start] = true;
	cout << start << " ";
	for (int i = 1; i <= n; i++)
	{
		if (map[start][i] == 1 && !visited[i])
			dfs(i);
	}
}

void bfs(int start)
{
	queue<int> queue;

	queue.push(start);
	visited[start] = true;
	while (!queue.empty())
	{
		int current_vertex = queue.front();
		queue.pop();

		cout << current_vertex << " ";
		for (int i = 1; i <= n; i++)
		{
			if (map[current_vertex][i] == 1 && !visited[i])
			{
				queue.push(i);
				visited[i] = true;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		map[v1][v2] = 1;
		map[v2][v1] = 1;
	}

	dfs(start);
	for (int i = 0; i < MAX; i++)
	{
		visited[i] = false;
	}
	cout << "\n";
	bfs(start);
}