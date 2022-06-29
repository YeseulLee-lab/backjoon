#include <array>
#include <iostream>

using namespace std;

int n;
int cnt = 0;
array<int, 15> board; // 배열 길이가 행, 넣는 값은 열

bool promising(int cdx)
{
	for (int i = 0; i < cdx; i++)
	{
		if (board[i] == board[cdx] || cdx - i == abs(board[cdx] - board[i]))
			return false;
	}
	return true;
}

void nQueen(int cdx)
{
	if (n == cdx) //끝까지 넣었다면 성공
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)//(cdx, 0 ~ n-1)
	{
		board[cdx] = i;
		if (promising(cdx))
		{
			nQueen(cdx + 1);
		}
	}
}

int main()
{
	cin >> n;
	nQueen(0);//(0,-) 부터 넣어본다.
	cout << cnt;
}