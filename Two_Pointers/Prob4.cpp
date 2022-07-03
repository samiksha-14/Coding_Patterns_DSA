// Problem Statement
//Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all 
//the elements in the subarray is strictly less than k.
/*
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than 100
*/
// My code

#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //here we do not need to sort the array bec we will not be shrinking our window on the basis of elements
        int start=0,end=0,prod=1,ans=0;
        while(end<nums.size()){
            prod*=nums[end];
            //include the current element into the product so far
            //now check if your product become greater then shrink the window else count the subarrays
            while(prod>=k && start<end){
                prod/=nums[start];
                start++;
            }
            if(prod<k) ans+=end-start+1;
            //if the whole subarray prod is less than k then obviously the subarrays of that particular subarray will also be having less
            //product so include that into your ans
            end++;
        }
        return ans;
        
    }
  
int main()
{
    
    vector<int> nums{10,5,2,6};
    cout<<numSubarrayProductLessThanK(nums,100);
   
}
/*
This is a two pointer+sliding window problem ... starting from the first index you have to include elements one by one in your window and then
calculate its product, if product is less than the target you should inlude all the subarray inside that window in your ans(because if the product of
all the elements inside the subarray is < target then obviously the individual subarrays will produce less product than the target) and then increment your
pointer
But if your product becomes greater than the target just shrink your window and divide the element that you are going to remove from your window with the
product so far
Time Complexity --> O(N)
Space Complexity --> O(1)
*/