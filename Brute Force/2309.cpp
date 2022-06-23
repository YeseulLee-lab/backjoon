#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main(void)
{
	array<int, 9> dwarfs_h;
	int sum = 0;

	for (int i = 0; i < dwarfs_h.size(); i++)
	{
		cin >> dwarfs_h[i];
		sum += dwarfs_h[i];
	}

	sort(dwarfs_h.begin(), dwarfs_h.end());

	for (int i = 0; i < dwarfs_h.size() - 1; i++)
	{
		for (int j = 1; j < dwarfs_h.size(); j++)
		{
			if ((sum - (dwarfs_h[i] + dwarfs_h[j])) == 100)
			{
				for (int k = 0; k < dwarfs_h.size(); k++)
				{
					if (k != i && k != j)
						cout << dwarfs_h[k] << endl;
				}
				return 0;
			}
		}
	}
}