#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	queue<int> cards;

	for (int i = 0; i < N; i++)
	{
		cards.push(i+1);
	}

	while (cards.size() >= 1)
	{
		if (cards.size() == 1)
		{
			cout << cards.front();
			return 0;
		}
		cards.pop();
		int temp = cards.front();
		cards.pop();
		cards.push(temp);
	}

	cout << cards.front();

	return 0;
}