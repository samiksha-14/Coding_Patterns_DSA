// Problem Statement
//You are climbing a staircase. It takes n steps to reach the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
/*
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
// My code
//recursion+memoization
#include <bits/stdc++.h>
using namespace std;

  int climbStairs(int n,vector<int>&dp){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n-1]!=-1) return dp[n-1];
        return dp[n-1]=climbStairs(n-1,dp)+climbStairs(n-2,dp);
    }
int main()
{
    int n;cin>>n;
    vector<int>dp(n,-1);
   cout<<"-->"<<climbStairs(n,dp);
   
}
/*
the total number of choices for n stairs is T(n) = T(n-1) + T(n- 2).
while having the recursive calls we are encountering repeating sub problems therfore apply memoization to store the 
result of those sub problems, in this way we will be saved from the overhead of making 2^n calls.
Time Complexity --> O(N)
Space Complexity --> O(N) 
*/
