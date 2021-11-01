#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int size, vector<vector<int>> &v, vector<int> op)
{
    if (size == 0)
    {
        v.push_back(op);
        return;
    }
    vector<int> op1 = op;
    vector<int> op2 = op;
    op2.push_back(a[0]);
    solve(a + 1, size - 1, v, op1);
    solve(a + 1, size - 1, v, op2);
}

int main()
{
    int t;
    cout << "Enter the size of a set\n";
    cin >> t;
    int a[t];
    vector<vector<int>> v;
    vector<int> op;
    for (int k = 0; k < t; k++)
    {
        cin >> a[k];
    }
    solve(a, t, v, op);
    cout << "Subsets are : \n";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
