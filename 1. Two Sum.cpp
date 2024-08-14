/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //We will use a hashtable in which we will store the numbers in the array.
        //For each number we will check if we also found its complement.
        //Complexity: O(n)

        unordered_map<int, int> aux;
        unordered_map<int, int>::iterator elem;

        //Go through the array
        for(int i = 0; i < nums.size(); i++)
        {
            //Check if the complement was also found. If yes we found an answer.
            if((elem = aux.find(target - nums[i])) != aux.end())
            {
                return {i, elem->second};
            }
            aux[nums[i]] = i;
        }
        return {};
    }
};
