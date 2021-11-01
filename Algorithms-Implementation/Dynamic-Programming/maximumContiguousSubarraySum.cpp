#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

    int n, i;
    cin >> n;
    int arr[n] = { 0 };
    for(i = 0; i < n; i++)
        cin >> arr[i];
    
    int overallMax = INT_MIN, runningMax = 0;
    for(i = 0; i < n; i++) {
        runningMax += arr[i];
        if(overallMax < runningMax)
            overallMax = runningMax;

        if(runningMax < 0)
            runningMax = 0;
    }
    cout << overallMax << endl;
    
    return 0;
}
