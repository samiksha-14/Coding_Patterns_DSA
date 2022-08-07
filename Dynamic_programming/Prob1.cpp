// Problem Statement
//Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack with a capacity ‘C.’ The goal is to get the maximum profit out of the knapsack items.
//Each item can only be selected once, as we don’t have multiple quantities of any item.
/*
Items: { Apple, Orange, Banana, Melon }
Weights: { 2, 3, 1, 4 }
Profits: { 4, 5, 3, 7 }
Knapsack capacity: 5

Let’s try to put various combinations of fruits in the knapsack, such that their total weight is not more than 5:
Apple + Orange (total weight 5) => 9 profit
Apple + Banana (total weight 3) => 7 profit
Orange + Banana (total weight 4) => 8 profit
Banana + Melon (total weight 5) => 10 profit

This shows that Banana + Melon is the best combination as it gives us the maximum profit, and the total weight does not exceed the capacity.
*/
// My code
//recursion+memoization
#include <bits/stdc++.h>
using namespace std;

 int knapsack(vector<int>&w,vector<int>&val,int cap,int n,vector<vector<int>>&dp){
    //base case
    if(n<0 || cap<=0) return 0;
    //if value already computed then just return that value don't compute further
    if(dp[n][cap]!=-1) return dp[n][cap];
    //if weight of current item is less than or equal to the weight of knapsack then we have two choice:
    //1)we can include current item
    //2)we can exclude current item
    //we will choose whatever is giving us the max profit from above two choices hence we will calculate the max of it
    if(w[n]<=cap)
    return dp[n][cap]=max(val[n]+knapsack(w,val,cap-w[n],n-1,dp),knapsack(w,val,cap,n-1,dp));
    else 
    return dp[n][cap]=knapsack(w,val,cap,n-1,dp);//(the weight of knapsack becomes less than the weight of item so we cannot include it)

 }
int main()
{
    vector<int> profit{1, 6, 10, 16};
    vector<int>weights{1, 2, 3, 5};
    int capacity=7;
    int n=weights.size();
    vector<vector<int>>dp(n+1,vector<int>(capacity+1,-1));
    cout<<"..."<<knapsack(weights,profit,capacity,n-1,dp);
   
}
/*
The idea is to consider all the subsets of items such that the total weight of the selected items is less than or equal to capacity of knapsack.
and whenever we find an element whose weight is less than or equal to the weight of the knapsack we then get two choices either we can include that
item in our knapsack or we can exclude it. but from both the choices we will select the one which is giving us the maximum profit.
when we go with choice 1 we add the value of item to our profit ans subtract the weight of that item from the capacity .
when we go with choice 2 we do not add anything we just proceed to find the answer from upcoming set of values.
while useing recursive solution The main problem was that a particular subproblem is solved multiple times. Thus to prevent
this we store the intermediate results in vector. that is memoization(recursion+storge)
So,before making any recursive call at first we check whether we have already calculated that value in the past. If so, we directly return the result of that particular subproblem without making the recursive call.
Otherwise, we make the recursive call and store the result of that particular subproblem.
Time Complexity --> O(N * capacity)
Space Complexity --> O(N * capacity) 
*/