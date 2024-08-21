/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //We will use a multiple bsf approach.
        //We will add all 0 cells to a queue and do a classic bfs, updating distances for all non
        //0 cells. The only difference is that we have multiple starting points
        //Complexity: O(n*m)
        
        if(mat.empty() || mat[0].empty())
            return {};

        //find sizes and compute max value
        int n = mat.size();
        int m = mat[0].size();
        int MAX_VAL = n * m;

        queue<pair<int, int>> queue;

        //add all 0 cells to the queue and set the others to max value
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mat[i][j] == 0)
                    queue.push({i,j});
                else
                    mat[i][j] = MAX_VAL;

        vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        //bfs
        while(!queue.empty())
        {
            auto [row, col] = queue.front();
            queue.pop();
            for(auto [dr, dc] : dir)
            {
                int r = row + dr;
                int c = col + dc;
                if(r >= 0 && r < n && c >= 0 && c < m && mat[r][c] > mat[row][col] + 1)
                {
                    queue.push({r,c});
                    mat[r][c] = mat[row][col] + 1;
                }
            }
        }

        return mat;
    }
};
