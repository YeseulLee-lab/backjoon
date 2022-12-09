#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<int> xvec;
vector<int> yvec;

void hanoi(int N, int x, int y)
{
	if (N > 1)
		hanoi(N - 1, x, 6 - x - y);

	xvec.emplace_back(x);
	yvec.emplace_back(y);
	cnt++;

	if (N > 1)
		hanoi(N - 1, 6 - x - y, y);
}

int main(void)
{
	int N;
	cin >> N;

	hanoi(N, 1, 3);
	cout << cnt << '\n'; //1에서 3으로 옮김

	for (int i = 0; i < cnt; i++)
	{
		cout << xvec[i] << ' ' << yvec[i] << '\n';
	}
}