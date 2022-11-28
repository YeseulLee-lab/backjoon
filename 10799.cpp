#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	int count = 0;
	stack<char> stk;

	bool isPipe = false;

	string brackets;
	cin >> brackets;

	for (int i = 0; i < brackets.size(); i++)
	{
		if (brackets[i] == '(')
		{
			stk.push(brackets[i]);
			isPipe = true;
		}	
		else
		{
			if (isPipe)
			{
				stk.pop();//레이저 여는 괄호 pop
				count += stk.size();
				isPipe = false;
			}
			else
			{
				count++;//잘리는 끝부분
				stk.pop();//파이프 끝남
			}
		}
	}
	cout << count;
}