#include <bits/stdc++.h>
using namespace std;

void solve(string in, string op)
{
    if (in.size() == 0)
    {
        cout << op<< endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    string help = op;
    op1.push_back(in[0] + 48);
    help.push_back(in[0]);
    help.push_back(in[1]);
    in.erase(in.begin() + 0);
    solve(in, op1);
    stringstream geek(help);
    int newValue = 0;
    geek >> newValue;
    if (newValue <= 26)
    {
        newValue += 97;
        op2.push_back(newValue);
        in.erase(in.begin() + 0);
        solve(in, op2);
    }
}

int main()
{
    string in, op = "";
    cin >> in;
    solve(in, op);
    return 0;
}
