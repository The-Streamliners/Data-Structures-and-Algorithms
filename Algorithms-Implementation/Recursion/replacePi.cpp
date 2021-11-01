// Replace the pi with 3.14 in a string
#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    if (s[0] == 'p' && s[1] == 'i')
    {
        string s2 = s.substr(2);
        cout << 3.14;
        solve(s2);
    }
    else
    {
        cout << s[0];
        string s2 = s.substr(1);
        solve(s2);
    }
}

int main()
{
    string s;
    cin >> s;
    cout << "Before Replacing pi with 3.14 , s = " << s << endl;
    cout << "After Replacing pi with 3.14 s = ";
    solve(s);
    return 0;
}
