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
				stk.pop();//������ ���� ��ȣ pop
				count += stk.size();
				isPipe = false;
			}
			else
			{
				count++;//�߸��� ���κ�
				stk.pop();//������ ����
			}
		}
	}
	cout << count;
}