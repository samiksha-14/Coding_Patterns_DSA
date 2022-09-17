// Problem Statement
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint
// stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two
// adjacent houses were broken into on the same night.Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without
// alerting the police.
/*
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/
// My code
///..................bottom-up dp....................
#include <bits/stdc++.h>
using namespace std;
int rob(vector<int> &nums)
{
    // can only rob alternate houses
    // so either i can start from first house or i can start from second house
    // ans=max(selecting first and its non adj,selecting second and its non adj)
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
}
int main()
{
    vector<int> nums = {2,7,9,3,1};
    cout << rob(nums);
}
/*
In the above problem if we are robbing ith house then we cannot rob adjacent(i+1)th house, because robbing adjacent house will alert the police
So, in a each recursive call we have got two choices
1)we can rob the house or 2)we cannot rob the house
If we are going with the first one we cannot make call to the adjacent element of it
But, if we are going with the second call then we can make recursive call for just the next element
Since we have to return the maximum money we will take the maximum of both the choices
While we go into recursion we will encounter some repeating subproblems so we have to use dynamic programming here
Time Complexity --> O(n)
Space Complexity --> O(n)
*/

//....................recursion..................//////////////////////////
// int rob(vector<int>&nums,int n){
//     if(n==0) return nums[n];
//     if(n<0) return 0;
//     return max(nums[n]+rob(nums,n-2),0+rob(nums,n-1));
// 
//}
///.................recusrsion+memoization.........///////////
// int rob(vector<int>&nums,int n,vector<int>&dp){
//     if(n==0) return nums[n];
//     if(n<0) return 0;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n]=max(nums[n]+rob(nums,n-2,dp),0+rob(nums,n-1,dp));
// 
//}