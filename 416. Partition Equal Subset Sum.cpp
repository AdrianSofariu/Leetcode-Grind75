/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].


Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

class Solution {
public:

    bool f(vector<int> &arr, int i, int sum, vector<vector<int>> &dp)
    {
        //if we have no elements
        if(i == 0)
            return arr[i] == sum;

        //if we can get the sum using all i elements
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        if(sum == 0)
            return true;

        if(sum < 0)
            return false;

        //search a partition
        bool p = false;
        if(arr[i] <= sum)
            p = f(arr, i-1, sum-arr[i], dp);
        bool p2 = f(arr, i-1, sum, dp);

        return dp[i][sum] = p || p2;
    }


    bool canPartition(vector<int>& nums) {
        //First we compute the sum. If it is odd we cannot have a partition with equal sums.
        //Then we check if we have a partition of value sum/2.
        //Complexity: O(n x sum)
        int sum = 0;
        for(int x : nums)
            sum += x;
        
        if(sum % 2 != 0)
            return false;

        sum /= 2;
        int n = nums.size();

        //build table for memoization
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return f(nums, n-1, sum, dp);
    }
};
