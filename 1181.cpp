#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vec;

bool compare(string a, string b)
{
	if (a.length() == b.length())
		return a < b;//길이가 같으면 사전순
	return a.length() < b.length();//길이순으로 정렬
}

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		vec.emplace_back(str);
	}

	sort(vec.begin(), vec.end(), compare);	

	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << '\n';
	}
}