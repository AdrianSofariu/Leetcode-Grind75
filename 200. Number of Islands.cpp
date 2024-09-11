/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1


Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

class Solution {
private:
    //vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    
    //classic bfs
    void bfs(vector<vector<char>>& grid, int r, int c, int rows, int cols){
        queue<pair<int, int>> q;
        q.push({r,c});
        //mark as visited
        grid[r][c] = '0';

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            //enqueue the 4 possible neihbours if they meet the criteria
            for(int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    //mark as visited
                    grid[nr][nc] = '0';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols){
        if(r < 0 || r >= rows || c < 0 || c >= cols ||grid[r][c]=='0'){
            return;
        }

        //mark as visited
        grid[r][c] = '0';

        //recure for neighbours
        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
        dfs(grid, r, c + 1, rows, cols);   
    }


public:
    int numIslands(vector<vector<char>>& grid) {
        //We will use a bfs-based solution. When we find a '1' cell
        //we call a bfs checking top, right, bottom and left. We will set a position to 0
        //after we visit it to save time and space.
        //Each time we start a new bfs we have a new island.
        //Complexity: O(r * c) - time, O(r * c) - space
        //Also included a dfs version.

        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        //Go over the grid
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                //for each new 1 cell, add an island and start a bfs/dfs
                if(grid[r][c] == '1'){
                    islands++;
                    //dfs(grid, r, c, rows, cols);
                    bfs(grid, r, c, rows, cols);
                    
                }
            }
        }

        return islands;
    }
};
