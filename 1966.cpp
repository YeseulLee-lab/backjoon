#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int test;
	cin >> test;
	
	vector<int> result;
	
	for (int i = 0; i < test; i++)
	{
		int n, m; 
		int count = 1;
		cin >> n >> m;

		queue<int> que;
		queue<int> indexque;
		vector<int> priority;
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			que.push(temp);
			indexque.push(j);
			priority.emplace_back(temp);
		}

		sort(priority.begin(), priority.end());

		while (!que.empty())
		{
			if (que.front() == priority[n - 1])
			{
				if (indexque.front() == m)
				{
					result.push_back(count);
					break;
				}
				que.pop();
				indexque.pop();
				priority.pop_back();
				count++;
				n--;
			}
			else
			{
				int temp = que.front();
				int temp2 = indexque.front();
				
				que.pop();
				indexque.pop();
				que.push(temp);
				indexque.push(temp2);
			}
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}

}