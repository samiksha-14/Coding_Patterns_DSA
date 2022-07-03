// Problem Statement
//Given an array containing 0s, 1s and 2s, sort the array in-place.
/*
Input: [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
*/
// My code

#include <bits/stdc++.h>
using namespace std;
void sort(vector<int> &nums) {
   int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
           else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                    high--;
            }
            else if(nums[mid]==1)
                mid++;
        }
        
  }
int main()
{
    
    vector<int> arr{1,2,0,1,2,0};
    sort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
   
}
/*
This problem can be solved by using three pointers , with the help of these three pointers we will place the elements
0s,1s,2s at there correct position
throught the iteration of the array we will assume that mid is pointing to unkown value, start is pointing to 0 and high is
pointing to 2...so with the help of mid pointer we will place the 0s and 2s we encounter at their correct position
Time Complexity --> O(N)
Space Complexity --> O(1)
*/