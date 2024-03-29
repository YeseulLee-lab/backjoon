#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int cnt;

int recursion(const char* s, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cnt = 0;
        char S[1001];
        scanf("%s", S);

        cout << isPalindrome(S) << ' ' << cnt << '\n';
    }
}