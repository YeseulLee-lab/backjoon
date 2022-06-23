#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	int m;
	vector<int> cards;


	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;
		cards.push_back(num);
	}

	vector<int> cards_select;

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if ((cards[i] + cards[j] + cards[k]) <= m)
				{
					cards_select.push_back(cards[i] + cards[j] + cards[k]);
				}
			}
		}
	}

	sort(cards_select.begin(), cards_select.end());
	cout << cards_select[cards_select.size() - 1];
}