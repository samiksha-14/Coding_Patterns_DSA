// Problem Statement
//Given an array of unsorted numbers, find all unique triplets in it that add up to zero.
/*
Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.
*/
// My code

#include <bits/stdc++.h>
using namespace std;

 vector<vector<int>> threeSum(vector<int>& nums) {
         int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        //now apply two pointer approach
        for(int i=0;i<n-2;i++){
        if(i==0 ||( i>0 && nums[i]!=nums[i-1])){
        int a=0-nums[i];
         int low=i+1,high=n-1;          
         while(low<high){                    
             int sum=nums[low]+nums[high];
             if(sum==a){
                 res.push_back({nums[i],nums[low],nums[high]});
                 do{
                     low++;
                 }
                 while(low<high && nums[low]==nums[low-1]);
                 do{
                     high--;
                 }
                 while(low<high && nums[high]==nums[high+1]);
             }
             else if(sum<a) low++;
             else high--;
             }
         }
        }
        return res;
  }
  
int main()
{
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int>>res=threeSum(nums);
    for(auto triplet:res){
         cout<<triplet[0]<<" "<<triplet[1]<<" "<<triplet[2]<<"\n";
        cout<<endl;
    }
   
}
/*
This problem is kind of similar to two sum problem, in two sum problem we have to find two numbers and b such that a+b=x
but here we have to find three numbers such that a+b+c=0...if we simplify this equation further it results in b+c=-a
hence again we have to find two numbers b and c such that their sum is -a..but the only difference here is third number
exist in the array itself
so we will first sort the array and while iterating over the array we will chose -a and for that we will iterate over the
rest of array to find two number results in sum -a
Time Complexity --> O(N * logN + N^2)=O(N^2)
Space Complexity --> O(N)
*/