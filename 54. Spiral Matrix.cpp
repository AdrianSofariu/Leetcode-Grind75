/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]


Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //We just simulate the traversal
        //Complexity: O(n*m) - time, O(1) - space 

        int l = 0, u = 0, r = matrix[0].size() - 1, d = matrix.size() - 1;
        vector<int> ans;

        if(matrix.empty())
            return ans;

        while(l <= r && u <= d){

            //add top row
            for(int i = l; i <= r; i++)
                ans.push_back(matrix[u][i]);
            //move upward limit down one level
            u++;

            //add right column
            for(int i = u; i <= d; i++)
                ans.push_back(matrix[i][r]);
            //move right limit to the left
            r--;

            //add bottom row
            if(u <= d){
                for(int i = r; i >= l; i--)
                    ans.push_back(matrix[d][i]);
                //move downward limit up one level
                d--;
            }

            //add left column
            if(l <= r){
                for(int i = d; i >= u; i--){
                    ans.push_back(matrix[i][l]);
                }
                //move left limit to the right
                l++;
            }

        }
        return ans;
    }
};
