#include <bits/stdc++.h>
using namespace std;

void solve(int n, int &count)
{
    if (n == 0)
    {
        count++;
        return;
    }

    if (n >= 1)
        solve(n - 1, count);
    if (n >= 2)
        solve(n - 2, count);
    if (n >= 3)
        solve(n - 3, count);
}

int main()
{
    int n;
    string ways = "";
    cin >> n;
    int count = 0;
    solve(n, count);
    cout << count;
    return 0;
}
