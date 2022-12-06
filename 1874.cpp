#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int num = 1;
	stack<int> stk;
	vector<char> result;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		while (x >= num)
		{
			stk.push(num);
			result.emplace_back('+');
			num++;
		}

		if (stk.top() == x)
		{
			stk.pop();
			result.emplace_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
		
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<<'\n';
	}
}