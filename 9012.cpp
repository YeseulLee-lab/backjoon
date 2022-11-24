#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string vps;
		cin >> vps;

		if (vps.size() % 2 == 0)
		{
			stack<char> stk;
			for (int j = 0; j < vps.size(); j++)
			{
				if (vps[j] == '(')
				{
					stk.push(vps[j]);
				}
				else
				{
					if (!stk.empty() && stk.top() == '(')
						stk.pop();
					else
						stk.push(vps[j]);
				}
			}
			if (stk.empty())
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
			cout << "NO\n";
	}
}