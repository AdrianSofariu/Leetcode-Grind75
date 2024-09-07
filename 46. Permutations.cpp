/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

class Solution {
private:
    
    void solve(vector<vector<int>> &ans, vector<int> &nums, int index){
        //if the current index is equal to the size of nums, we have a solution
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        //iterate over all remaining elements
        for(int j = index; j < nums.size(); j++){
            //swap current with element at position j
            swap(nums[index], nums[j]);
            //recursively generate permutations for next index
            solve(ans, nums, index + 1);
            //revert swap
            swap(nums[j], nums[index]);
        }
    }

    

public:
    vector<vector<int>> permute(vector<int>& nums) {
        //We will do a backtracking algorithm
        //Complexity: O(n!) - time, O(n) - space
        vector<vector<int>> ans;
        int index = 0;
        solve(ans, nums, index);
        return ans;
    }
};
