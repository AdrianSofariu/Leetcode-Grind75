/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

class Solution {
public:
//To solve this problem we use Boyer-Moore Majority Voting Algorithm
//Complexity: O(n) - time, O(1) - space 
    int majorityElement(vector<int>& nums) {
        
        int count = 0, candidate;

        //iterate through the array
        for(auto number : nums){
            if(count == 0)
                candidate = number;
            if(number == candidate)
                count++;
            else
                count--;  
        }

        //because the answer is guaranteed to exst we dont need to do this anymore
        /*int votes = 0;
        for(auto n : nums)
        {
            if(candidate == n)
                votes++;
        }
        if(votes > nums.size()/2)*/
        return candidate;
    }
};
