/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

class Solution {
public:

    //We will do a non-recursive backtracking solution
    //Complexity: O(n * (2^n)) - time, O(1) - space
    vector<vector<int>> subsets(vector<int>& nums) {
       
        int n = nums.size();

        //a set of n elements has 2^n subsets
        int subsets = 1<<n; 

        //already reserve space for each subset
        vector<vector<int>> ans(subsets);

        //very intereseting approach i found
        //use the binary representation of the subset number
        //as an array where each bit set to 1 represents the inclusion of the
        //number on that position in the nums array in the subset.
        for(unsigned i = 0; i < subsets; i++){

            //reserve as many positions and 1's in the binary representation of i
            ans[i].reserve(popcount(i));

            //iterate over each element
            for(int idx = 0; idx < n; idx++){
                //if the bitwise and is not 0 (the respective position is 1 in the binary representation
                //of i), add it
                if(i & (1<<idx))
                    ans[i].push_back(nums[idx]);
            }
        }

        return ans;
    }
};
