/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.

 
Example 1:

Input: m = 3, n = 7
Output: 28


Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


Constraints:

1 <= m, n <= 100

*/


//Maths
class Solution {
public:
    int uniquePaths(int m, int n) {
        //The robot can move m-1 moves down and n-1 moves to the right. So it will
        //always move m+n-2 times. To find the number of paths we need all combinations
        //of m-1 moves down and n-1 right so we use N!/(r!(N-r)!).
        //N = m+n-2
        //r = m-1 or n-1 (it makes no difference)
        //as the result is always C=(m+n-2)!/((n-1)!(m-1)!)
        //Complexity: O(m) - time, O(1) - space
        long long result = 1;
        long long k = m - 1, N = m + n - 2;

        for(int i = 1; i <= k; i++)
            result = result * (N - k + i)/i;
        return result;
    }
};

//Dp variant
#include <vector>
using std::vector;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //Intialize the array with n elements of value 1
        //This is the top row, where each position can be reached in 1 way
        vector<int> dp(n, 1);

        //Loop m-1 times for each remaining row
        for (int p = 1; p < m; ++p) {
            //iterate over each column besides the left ones (because we only reach them in 1 way)
            for (int i = 1; i < n; ++i) {
                //the value of the new position is the sum of the position above and to the left
                dp[i] += dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};
