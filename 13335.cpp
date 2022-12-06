#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int totalL(queue<int> que)
{
	int total = 0; 
	while(!que.empty())
	{
		total += que.front();
		que.pop();
	}
	return total;
}

int main(void)
{
	int n, w, l;
	int time = 0;
	cin >> n >> w >> l;

	queue<int> truck;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		truck.push(temp);
	}

	vector<int> vec;
	queue<int> bridge;
	while (vec.size() < n)
	{
		if (bridge.size() == w)
		{
			vec.emplace_back(bridge.front());
			bridge.pop();
			while (!bridge.empty() && bridge.front() == 0)
			{
				bridge.pop();
			}
		}
		if (bridge.size() < w)
		{
			if (totalL(bridge) < l && !truck.empty() && (totalL(bridge) + truck.front()) <= l)
			{
				bridge.push(truck.front());
				truck.pop();
			}
			else
			{
				bridge.push(0);
			}
		}
		time++;
	}

	cout << time;
}