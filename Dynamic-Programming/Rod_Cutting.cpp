/**

The Problem

There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. Now, there are M weak points on this rod denoted by positive integer values(all less than N) A1, A2, …, AM. You have to cut rod at all these weak points. You can perform these cuts in any order. After a cut, rod gets divided into two smaller sub-rods. Cost of making a cut is the length of the sub-rod in which you are making a cut.

Your aim is to minimise this cost. Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give same cost, return the lexicographically smallest.

Notes:

    Sequence a1, a2 ,…, an is lexicographically smaller than b1, b2 ,…, bm, if and only if at the first i where ai and bi differ, ai < bi, or if no such i found, then n < m.
    N can be upto 109.

For example,

N = 6
A = [1, 2, 5]

If we make cuts in order [1, 2, 5], let us see what total cost would be.
For first cut, the length of rod is 6.
For second cut, the length of sub-rod in which we are making cut is 5(since we already have made a cut at 1).
For third cut, the length of sub-rod in which we are making cut is 4(since we already have made a cut at 2).
So, total cost is 6 + 5 + 4.

Cut order          | Sum of cost
(lexicographically | of each cut
 sorted)           |
___________________|_______________
[1, 2, 5]          | 6 + 5 + 4 = 15
[1, 5, 2]          | 6 + 5 + 4 = 15
[2, 1, 5]          | 6 + 2 + 4 = 12
[2, 5, 1]          | 6 + 4 + 2 = 12
[5, 1, 2]          | 6 + 5 + 4 = 15
[5, 2, 1]          | 6 + 5 + 2 = 13


So, we return [2, 1, 5].




*/










/**

The Approach

lets find the parent prblem and child subproblems


if my rod has no mark
the answer is 0 cost


it my rod has 1 mark
then, there is just one choice ..to choose the mark and cut the rod ...cost = length or rod


if my rod has 2 marks
then choice is to ...chose the mark ..such the the cost in remaining child rods is less...

so the child starts from length 0 to 1 to 2 ....and so on...in determining parent....


1. OptimalSubstructure
  yes ..child probl contributes to answer of parent problem ..atleast recursive solution
  
2. Overlapping subproblems
  yes ..memoize
  
3. Element of choice
  If current rod is from mark ith to jth.....and there are K marks in b/w
  I can choose any of the kth mark to cut the rod..
  But, i'll chose that mark, which gives the minimum cost...to for further child rods..that the cutting would create.
      moreover as per quetions demands, if two poitns give same min cost,, chose the left most..lexicigraphlly less

4. What will state represent
   a state can store the cost to cut the rod ...for a rod that exists b/w ith mark to jth mark...
   
5. Recurrence relation
    for rod b/w ith mark to jth mark
    costi,j  == length of rod   +    min of (cost of leftchild + cost of right child) {if kth mark divides rod b/w i, j} 
             == pos[j]-pos[i]   +   min (cost[i][k] + cost[k][j]) 
             
6. Base cases
   if mark i just next to mark j ...and not mark in b/w ...i.e. no mark on rod...  cost = 0
   
7. To get answer..
  we backtrack from .. parent rod ...and keep chosing the child rod..based on min cost already calculated.
  and keep forming the resutlant answer array of the marks to choose to give min cost.

*/







vector<int> getPath(vector< vector <long long>> &cost, vector<int> &B, int i, int j){
    vector<int> ans;
    
    long long minc = LONG_MAX;
    for(int k = i+1 ; k < j ; k++){
        if( ( cost[i][k]  + cost[k][j] + ((long long)( B[j-1]- B[i-1])) ) == ( cost[i][j] ) ){

            ans.push_back(B[k-1]);
            vector<int> left = getPath(cost, B, i, k);
            vector<int> right = getPath(cost, B, k, j);
            for(int l = 0; l < left.size() ; l++)
                ans.push_back(left[l]);
            for(int l = 0; l < right.size() ; l++)
                ans.push_back(right[l]);
            
            return ans;
        }
    }
    return ans;
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    
    
    B.insert(B.begin(), 0);
    B.push_back(A);
    int ptcnt = B.size();
    vector< vector <long long>> cost( ptcnt +1, vector<long long> (ptcnt+1, LONG_MAX));
    
    
    for(int i = 1 ; i <= ptcnt ; i++){
        cost[i][i] = 0;
    }
    for(int i = 2 ; i <= ptcnt ; i++){
        cost[i-1][i] = 0;
    }
    
    
    for(int len = 2 ; len <= ptcnt-1 ; len++ ){
        for(int i = 1 ; i+len <= ptcnt ; i++){
            int j = i+len;
            
            long long minc = LONG_MAX;
            for(int k = i+1 ; k < j ; k++){
                minc = min( minc, cost[i][k] + cost[k][j]);
            }
            
            cost[i][j] = (j == i+1) ? ((long long )(B[j-1]- B[i-1])) :  ((long long)(B[j-1]- B[i-1])) + minc;
        }
    }

    
    return getPath(cost, B, 1, ptcnt);
    
}







