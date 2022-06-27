// Problem Statement
//Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as
// possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.
/*
Input: [-2, 0, 1, 2], target=2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.
*/
// My code

#include <bits/stdc++.h>
using namespace std;

 int threeSumClosest(vector<int>& arr, int targetSum) {
        int minsum=INT_MAX,min_diff=INT_MAX;
     sort(arr.begin(),arr.end());
    //int i=0;
    for(int i=0;i<arr.size();i++)
    {
      int a=arr[i];
      int l=i+1,h=arr.size()-1;
      while(l<h){
        int b=arr[l];
        int c=arr[h];
        int sum=a+b+c;
        int curr_diff=abs(targetSum-sum);
        if(curr_diff<min_diff){
          min_diff=curr_diff;
          minsum=sum;
        }
        if(sum>targetSum) h--;
        else
        l++; 
      }
    }
    return minsum;
    }
int main()
{
    vector<int> nums{1,0,1,1};
    cout<<threeSumClosest(nums,100);
   
}
/*
This problem is kind of similar to two sum problem, in two sum problem we have to find two numbers and b such that a+b=x
but here we have to find three numbers such that sum is closest to the target...we can visualize it better with the help of
a number line.... that means the less the diffrence between the numbers the more closer they are to each other
So at every step, we will save the difference between the triplet and the target number,
so that in the end, we can return the triplet with the closest sum.
Time Complexity --> O(N * logN + N^2)=O(N^2)
Space Complexity --> O(N) (for sorting)
*/