/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.


Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.


Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.


Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //We will fix the first number, which leaves us with the Two Sum problem.
        //We will also sort the array.
        //This time we will use a 2 pointer approach to solve the two sum.
        //Complexity: O(n^2)

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); //O(nlogn)
        int n = nums.size();

        //fix first number
        int i = 0;
        for(int i = 0; i < n - 2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) //skip duplicates
                continue;

            //two sum
            int j = i + 1;
            int k = n - 1;
            
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    vector<int> v{nums[i], nums[j], nums[k]};
                    ans.push_back(v);

                    //move from right
                    k--;

                    //skip duplicates from right
                    while(j < k && nums[k] == nums[k+1])
                        k--;
                }
                else
                {
                    //update the 2 pointers
                    if(sum > 0)
                        k--;
                    else
                        j++;
                }
            }
        }
        return ans;
    }
};
