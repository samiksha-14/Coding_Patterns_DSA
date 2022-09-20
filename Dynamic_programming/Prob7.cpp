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
int check(bool buy,vector<int>&p,int n,int k,vector<vector<vector<int>>>&dp){
        if(k==2 || n>=p.size()) return 0;
        if(dp[n][buy][k]!=-1) return dp[n][buy][k];
        if(buy && k<2){
            //you can buy the stock
            int buying = -p[n]+check(0,p,n+1,k,dp);
            int not_b=check(buy,p,n+1,k,dp);
            return dp[n][buy][k]=max(buying,not_b);
        }
        else{
            int sell= p[n]+check(1,p,n+1,k+1,dp);
            int not_sell=check(buy,p,n+1,k,dp);
            return dp[n][buy][k]=max(sell,not_sell);
        }
    }
int main()
{
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        cout<< check(1,prices,0,0,dp);
}

/*
In the above given problem each index represents the price of stock and you have the choice to buy the stock if you have not before and you have the
choice to sell the stock if you have buyed before, so we have to calculate the maximum price we can get by doing atmost 2 transaction
Starting from the very first index you can always have the choice to buy that stock because that is the first one
Now for index other than 0 you have the choice to buy/sell stock so we will maintain a variable for it which will tell us if we have buyed any 
stock before if the value of 
///buy is 0 that means we cannot buy the stock then we are only left with the choice of selling
///buy is 1 that means we can buy the stock 
.........if we have the choice to buy the stock then we will go with the choice which is giving us the maximum result.....
///choice 1
YOU ARE BUYING THE STOCK 
if you are buying the stock the you will get the negative value of stock (price = sell-buy) then just proceed with further calls with value of 
buy as 0 because you have buyed and you cannot buy until you sell this one
///choice 2
if you are not buying the stock the you will get noting just proceed with further calls keeping the value of buy as it is
.........if we have the choice to sell the stock then we will go with the choice which is giving us the maximum result.....
if you are selling the stock then you will get the positive value of stock (price = sell-buy) then just proceed with further calls with value of 
buy as 1 because you have completed a transaction and now you can buy another stock and since you are done with the tranaction your number of
transaction will also be reduced by 1
///choice 2
if you are not selling the stock the you will get noting just proceed with further calls keeping the value of buy as it is

Here given this many choices we will apply dynamic programming
Time Complexity --> O(n)
Space Complexity --> O(n)
*/ 
//
