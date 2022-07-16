#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000
using namespace std;

int m, n;
int day = -1;
int arr[MAX][MAX];
int visited[MAX][MAX];
queue<pair<int, int>> que;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs()
{
	while (!que.empty())
	{
		int tx = que.front().first;
		int ty = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == 0 && arr[nx][ny] == 0)
			{
				visited[nx][ny] = visited[tx][ty] + 1;
				que.push({ nx, ny });
			}
		}
	}
}

int main()
{
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			visited[i][j] = 0;
			if (arr[i][j] == 1 && visited[i][j] == 0)
			{
				que.push({ i, j });
			}
		}
	}

	bfs();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (day <= visited[i][j])
				day = visited[i][j];
			if (visited[i][j] == 0 && arr[i][j] == 0)
			{
				day = -1;
				cout << day;
				return 0;
			}
		}
	}

	cout << day;
}