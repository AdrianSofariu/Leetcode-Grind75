/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //To get the most efficient solution, we will use a bfs technique
        //We will use a queue and we will add all rotten oranges. For each one,
        //we will check the neighbours and if they are fresh oranges, we will make them rotten.
        //At each iteration we will go through all rotten oranges in the queue and update the grid.
        //Complexity: O(mn)

        constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int n = grid.size();
        const int m = grid[0].size();
        int mins = 0;
        int countFresh = 0;
        queue<pair<int,int>> q;

        //Add the starting rotten oranges to the queue
        //and count the fresh ones
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1)
                    countFresh++;
                else if(grid[i][j] == 2)
                    q.emplace(i,j);

        if(countFresh == 0)
            return 0;

        while(!q.empty())
        {
            //increment the minute counter
            mins++;

            //update grid and queue
            for(int sz = q.size(); sz > 0; sz--)
            {
                //get a rotten orange
                const auto [i,j] = q.front();
                q.pop();

                //update neighbours
                for(auto& dir : dirs)
                {
                    int x = i + dir[0];
                    int y = j + dir[1];

                    //check bounds
                    if(x < 0 || x == n || y < 0 || y == m)
                        continue;
                    if(grid[x][y] != 1)
                        continue;

                    //mark as rotten
                    grid[x][y] = 2;
                    q.emplace(x,y);
                    countFresh--;
                }
            }
        }

        if(countFresh == 0)
            return mins - 1; // we started from min 1 not 0
        else
            return -1;
    }
};
