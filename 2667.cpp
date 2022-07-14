#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 25

using namespace std;

int n, cnt;
string arr[MAX];
vector<int> result;
bool visited[MAX][MAX];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> que;

void bfs(int x, int y)
{
	que.push({x, y});
	visited[x][y] = true;
	cnt++;
	while (!que.empty())
	{
		int v1 = que.front().first;
		int v2 = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = v1 + dx[i];
			int ny = v2 + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && arr[nx][ny] == '1')
			{
				que.push({ nx, ny });
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '1' && !visited[i][j])
			{
				cnt = 0;
				bfs(i, j);
				result.emplace_back(cnt);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
}