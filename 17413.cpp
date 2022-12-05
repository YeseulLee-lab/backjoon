#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	string S;
	string temp1, temp2 = "";
	bool isTag = false;
	getline(cin, S);

	stack<char> stk;

	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == '<' || isTag)
		{
			isTag = true;
			temp1 += S[i];
			while (!stk.empty())
			{
				cout << stk.top();
				stk.pop();
			}
		}

		if (!isTag)
		{
			if(i == (S.size() - 1))
				stk.push(S[i]);
			if (S[i] == ' ' || i == (S.size() - 1))
			{
				while (!stk.empty())
				{
					cout << stk.top();
					stk.pop();
				}
				cout << ' ';
			}
			else
				stk.push(S[i]);
		}

		if (S[i] == '>')
		{
			isTag = false;
			cout << temp1;
			temp1 = "";
		}
		
	}
}