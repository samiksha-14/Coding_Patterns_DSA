// Problem Statement
//Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target 
//where i, j, and k are three different indices. Write a function to return the count of such triplets
/*
Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]
*/
// My code

#include <bits/stdc++.h>
using namespace std;

 int threeSumSmaller(vector<int>& arr, int target) {
       int count = 0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-2;i++)
    {
      int a=arr[i];
      int left = i+ 1, right = arr.size() - 1;
    while (left < right) {
      if (arr[left] + arr[right] < target-a) { 
        // found the triplet
        // since arr[right] >= arr[left], therefore, we can replace arr[right] by any number between
        // left and right to get a sum less than the target sum
        count += right - left;
        left++;
      } else {
        right--;  // bec we need a pair with a smaller sum
      }
    }
    }
    return count;
    }
int main()
{
    vector<int> nums{-1,0,2,3};
    cout<<threeSumSmaller(nums,3);
   
}
/* 
first, we can sort the array and then iterate through it, taking one number at a time.
Let’s say during our iteration we are at number a, so we need to find b and c such that a + b + c < target
At this stage, our problem translates into finding a pair whose sum is less than target - c
(as from the above equation a+b == target - X). hence it got similar to 3 sum problem
Time Complexity --> O(N * logN + N^2)=O(N^2)
Space Complexity --> O(N) (for sorting)
*/