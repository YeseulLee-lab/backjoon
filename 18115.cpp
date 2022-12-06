#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int cardNum = 1;
	deque<int> card;
	vector<int> skills;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		skills.emplace_back(temp);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (skills[i] == 1)
		{
			card.push_front(cardNum);
		}
		else if (skills[i] == 2)
		{
			int temp = card.front();
			card.pop_front();
			card.push_front(cardNum);
			card.push_front(temp);
		}
		else if (skills[i] == 3)
		{
			card.push_back(cardNum);
		}
		cardNum++;
	}

	for (int i = 0; i < N; i++)
	{
		cout << card[i] << ' ';
	}
}