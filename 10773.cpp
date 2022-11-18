#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	stack<int> stk;

	int K, total = 0;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			total -= stk.top();
			stk.pop();
		}
		else
		{
			
			stk.push(temp);
			total += stk.top();
		}
			
	}

	if (stk.empty())
		cout << "0";
	else
		cout << total;
}