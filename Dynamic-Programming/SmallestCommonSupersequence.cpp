#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
void lcs(char* st1, char* st2,int s1,int s2)
{
    int LCS[s1+1][s2+1]; // create an array for storing max subsequence so far
    for(int i=0;i<=s1;i++)
    {
        for(int j=0;j<=s2;j++)
        {
            if(i==0||j==0) // filling the first column with zero
            {
                LCS[i][j]=0;
            }
            else if(st1[i-1]==st2[j-1]) // if the elements match
            {
                LCS[i][j]=LCS[i-1][j-1]+1; // fill the cell with diagonal element + 1
            }
            else
            {
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]); // else find the maximum of top and left element
            }
        }
    }
    cout<<"The minimum common supersequence length is : "<<s1+s2-LCS[s1][s2];
}

int main()
{
    char st1[MAX], st2[MAX];
    cout<<"Enter the first string: ";
    cin>>st1;
    cout<<"Enter the second string: ";
    cin>>st2;
    int s1,s2;
    s1=strlen(st1);
    s2=strlen(st2);
    lcs(st1,st2,s1,s2);
}
