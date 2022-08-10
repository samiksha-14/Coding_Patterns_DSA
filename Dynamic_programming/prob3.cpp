// Problem Statement
// Given an array of non-negative integers, and a value sum, determine if there is
// a subset of the given set with sum equal to given sum
/*
Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: True
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.
*/
// My code
//bottom-up approach (dp)
#include <bits/stdc++.h>
using namespace std;
 bool isSubsetSum(vector<int>nums, int k){
         int n=nums.size();
         vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
       for(int i=0;i<=n;i++){
           for(int j=0;j<=k;j++){
               if(i==0){
                   if(j==0) dp[i][j]=true;
                   else
                   dp[i][j]=false;
               }
              else if(j==0)
               dp[i][j]=false;
              else if(nums[i-1]<=j)
               dp[i][j]=(dp[i-1][j-nums[i-1]] || dp[i-1][j]);
               else
               dp[i][j]=dp[i-1][j];
           }
       }
       return dp[n][k];
    }
int main()
{
    vector<int>nums={3, 34, 4, 12, 5, 2};
int sum = 30;
    cout<<isSubsetSum(nums,sum);
}
/*
This problem is very much similar to 0/1 knapsack problem, we just have to identify the pattern.
there in the knapsack problem we were given the weight array and a capacity value of knapsack, here we can compare that weight array to our nums array
In the knapsack problem we were not able to include the item if its weight is greater than the weight of knapsack in that case we use to consider the
profit by not including that element, here we will do the same , if the element's value is greater than the sum that means we cannot choose that element
to be a part of our subset hence we just ignore it , but if the element's value is less than or equal to the sum we have the choice to include it or 
ignore it.
Time Complexity --> O(n*sum)
Space Complexity --> O(n*sum) 
*/
