#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void)
{
	char str[11] = {};
	cin >> str;

	int len = strlen(str);// str 길이

	int a[11];

	for (int i = 0; i < len; i++)
	{
		a[i] = str[i] - '0'; //askii 코드에서 0빼기
	}

	sort(a, a + len, greater<>()); //내림차순 정렬

	for (int i = 0; i < len; i++)
	{
		cout << a[i];
	}

	return 0;
}