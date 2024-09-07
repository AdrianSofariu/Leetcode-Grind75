/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.


Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.


Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
//We will use Kadane's dp algorithm to solve this
//Complexity: O(n) - time, O(1) - space
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int maxEnding = nums[0];
        int n = nums.size();

        //iterate through all elements
        for(int i = 1; i < n; i++){

            //find the maximum sum ending at index i by either extending the maximum
            //sum ending at i-1 or starting a new subarray from i
            maxEnding = max(maxEnding + nums[i], nums[i]);

            //update result
            res = max(maxEnding, res);
        }

        return res;
    }
};

