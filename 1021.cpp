#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(void)
{
	int N, M;
	int cnt = 0;
	cin >> N >> M;

	deque<int> deque;

	for (int i = 0; i < N; i++)
	{
		deque.emplace_back(i + 1);
	}

	for (int i = 0; i < M; i++)
	{
		int num, j;
		cin >> num;

		for (j = 0; j < deque.size(); j++)
		{
			if (deque[j] == num)
			{
				break;
			}
		}
		int mid = deque.size() / 2;

		while (deque.front() != num)
		{
			if (j <= mid)
			{
				deque.emplace_back(deque.front());
				deque.pop_front();
			}
			else
			{
				deque.emplace_front(deque.back());
				deque.pop_back();
			}
			cnt++;
		}
		
		deque.pop_front();
	}

	cout << cnt;

	return 0;
}