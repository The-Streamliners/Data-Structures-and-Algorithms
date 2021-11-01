//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
 void bt(vector<int>&a,vector<int>&crt,vector<vector<int>>&ans,vector<bool>&vis)
  {
      if((int)(crt.size()==(int)a.size()))
      ans.push_back(crt);
      for(int i=0;i<(int)a.size();i++)
      {
          if(vis[i])
          continue;
          if(i>0 && a[i]==a[i-1] && !vis[i-1])
          continue;
          vis[i]=true;
          crt.push_back(a[i]);
          bt(a,crt,ans,vis);
          vis[i]=false;
          crt.pop_back();
      }
  }
  vector<vector<int>>pd(vector<int>&a)
  {
  vector<vector<int>> ans;
        sort(a.begin(),a.end());
        vector<bool>vis((int)a.size(),false);
        vector<int>crt;
        bt(a,crt,ans,vis);
        return ans;
}
    vector<vector<int>> uniquePerms(vector<int> a ,int n) {
        // code here
        vector<vector<int>>ans=pd(a);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends