/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps


Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45

*/

class Solution {
public:
    int climbStairs(int n) {
        //We just need to know how to climb n-1 and n-2 stairs
        //We will use dynamic programming without memoization to compute this
        //knowing that we can climb 0 stairs and 1 stair in 1 way, and 2 in 2 ways.
        //So nr[n] = nr[n-1] + nr[n-2]
        //But we do not need an array for this as we only use the most recent 2 values
        //Complexity: O(n) - time, O(1) - space

        //trivial solutions
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;


        int minus1 = 1, minus2 = 2, aux;

        //dp approach
        for(int i = 3; i <= n; i++){
            aux = minus1 + minus2;
            minus1 = minus2;
            minus2 = aux;
        }

        return aux;
    }
};
