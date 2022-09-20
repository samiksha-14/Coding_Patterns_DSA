// Problem Statement
// You are given an integer array nums. You are initially positioned at the array's first index,
// and each element in the array represents your maximum jump length at that position.
//Return true if you can reach the last index, or false otherwise.
/*
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
// My code
///..................top-down dp....................
#include <bits/stdc++.h>
using namespace std;
bool jumps(vector<int> &nums,vector<int>&dp,int n)
{
    if(n==nums.size()) return true;
    if(nums[n]==0 || n>nums.size()) return false;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=nums[n];i++){
        dp[i]=jumps(nums,dp,n+i);
        if(dp[i]) return dp[i];
    }
    return false;
}
int main()
{
    vector<int> nums = {2,3,1,1,4};
    vector<int>dp(nums.size(),-1);
    cout << jumps(nums,dp,0);
}
/*
In the above given problem we are initially standing at index 0 and the value at 0th index is telling us the maximum jump we can take from the
index 0 and that is same for the every index and we have to determine if we can reach the end 
let us understand this with the help of an example
   indices  [0,1,2,3,4]
EXAMPLE:--> [2,3,1,1,4]
//remember the minimum jump that we can take is 1 because if the value at an index is 0 that means we cannot go anywhere from that
if we are standing at index 0 the maximum jump that we can take is of 2 (given maximum that means we can also take the jump lesser than 2)
//taking jump of length 2 we reach at index 2
    //now at index 2 we can only take jump of 1 and reach index 3
    //at index 3 we can take take jump of 1 and reach index 4 which is our final and end index hence ans will be true
//taking jump of length 1 and reach index 1........
so the above dry run tells us that standing at an ith index with value x(x!=0) we can take (1......x) jumps 
so at every index we have got different choices, hence it will undergo recursion and to optimize it we will use dynamic programming
Time Complexity --> O(n)
Space Complexity --> O(n)
*/ 
//}