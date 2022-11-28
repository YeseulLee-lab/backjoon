#include <iostream>
#include <stack>

using namespace std;

int num[26];

int main(void)
{
	int N;
	double result;
	cin >> N;

	string expr;
	cin >> expr;

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	stack<double> stk;
	for (int i = 0; i < expr.size(); i++)
	{
		if (isalpha(expr[i]))
		{
			stk.push(num[expr[i] - 65]);
		}
		else
		{
			double temp1 = stk.top();
			stk.pop();
			double temp2 = stk.top();
			stk.pop();

			if (expr[i] == '*')
			{
				result = temp1 * temp2;
				stk.push(result);
			}
			else if (expr[i] == '+')
			{
				result = temp1 + temp2;
				stk.push(result);
			}
			else if (expr[i] == '/')
			{
				result = temp2 / temp1;
				stk.push(result);
			}
			else if (expr[i] == '-')
			{
				result = temp2 - temp1;
				stk.push(result);
			}
		}
	}
	printf("%.2f", stk.top());
}