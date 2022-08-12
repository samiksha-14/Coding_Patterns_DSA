// Problem Statement
// Given a non-empty array nums containing only positive integers, find if the array can be partitioned into 
// two subsets such that the sum of elements in both subsets is equal.
/*
Input:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/
// My code
//bottom-up approach (dp)
#include <bits/stdc++.h>
using namespace std;
  bool check(int n,vector<vector<int>>&dp,int sum,vector<int>&nums){
        for(int i=0;i<=sum;i++){
            dp[0][i]=false;
        }
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
int main()
{
    vector<int>nums={1,5,11,5};
     int n=nums.size();
        int sum=0;
        for(int x:nums) sum+=x;
        int s=sum/2;
           if(sum%2!=0) return false;
        vector<vector<int>>dp(n+1,vector<int>(s+1,-1));
         cout<< check(n,dp,s,nums);
}
/*
This problem follows the 0/1 Knapsack pattern. A basic brute-force solution could be to try all combinations 
of partitioning the given numbers into two sets to see if any pair of sets has an equal sum.
lets assume that S represents the total sum of all the given numbers. Then the two equal subsets must have a sum equal to S/2. This transforms our 
problem to: "Find a subset of the given numbers that has a total sum of S/2".
Time Complexity --> O(n*s)
Space Complexity --> O(n*s) 
*/
