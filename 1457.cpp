#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void)
{
	char str[11] = {};
	cin >> str;

	int len = strlen(str);// str ����

	int a[11];

	for (int i = 0; i < len; i++)
	{
		a[i] = str[i] - '0'; //askii �ڵ忡�� 0����
	}

	sort(a, a + len, greater<>()); //�������� ����

	for (int i = 0; i < len; i++)
	{
		cout << a[i];
	}

	return 0;
}