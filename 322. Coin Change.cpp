/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1


Example 2:

Input: coins = [2], amount = 3
Output: -1


Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //We use a dynamic programming approach
        //For each value up to amount we compute the minimum nr of coins we need
        //Complexity: O(amount) - space, O(amount x coins.size()) - time

        vector<int> dp(amount + 1, INT_MAX - 1);

        //for value 0 we need 0 coins
        dp[0] = 0;
    

        //go through all coins (12 at max)
        for(int i = 0; i < coins.size(); i++){
            //we can use said coins for each value equal or higher to them
            for(int j = coins[i]; j <= amount; j++){
                //choose minimum
                dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
            }
        }

        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];

    }
};
