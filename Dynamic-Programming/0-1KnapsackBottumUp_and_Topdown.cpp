#include <iostream>
using namespace std;
int knapsackTopDown(int w , int weight[] , int value[], int n){
    if(n==0 || w==0){
        return 0;
    }
    if(weight[n] > w){
        return knapsack(w, weight, value, n-1);
    }
    return max(value[n] + knapsack(w-weight[n],weight, value, n-1), knapsack(w,weight, value, n-1) );
}
int knapsackBottomUp(int w , int weight[], int value[], int n){
   int dp[n+1][w+1];
   for(int i =0 ; i <= n ; i++){
       for( int j =0 ; j < w+1 ; j++){
           if( i== 0 || j == 0 ){
               dp[i][j] = 0;
           }
           else if(weight[i-1] <= j){
               dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i-1]]+value[i-1]);
           }
           else{
               dp[i][j] = dp[i-1][j];
           }
       }
   }
   return dp[n][w];
}
int main() {
    int n,w;
    cin>>n>>w;
    int weight[100];
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    int value[100];
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    cout<<knapsackBottomUp(w,weight, value , n)<<endl;
    cout<<knapsackTopDown(w,weight, value , n);
}
