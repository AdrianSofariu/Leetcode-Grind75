/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 
Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true


Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true


Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

Follow up: Could you use search pruning to make your solution faster with a larger board?

*/

class Solution {
    //This solution uses search pruning to optimize the solution, by checking
    //frequency of word characters on the board and reversing the searched string.
    //It could be further optimized by splitting the string in 2 if the lowest frequency
    //character is somewhere in the middle of the word.
    //Also you could save the positions of starting/ending letters of the word on the board.
    //Complexity: O(n * m * 4^wordLen) - time, O(rows * cols) - space
private:
    bool visit(vector<vector<char>>& board, vector<char>& word, int start, int x, int y, int n, int m, vector<vector<bool>>& visited){
        //vest case: if all characters are found, return true
        if(start == word.size())
            return true;

        //check if out of bounds or mismatch
        if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y])
            return false;

        //check if character matches
        if(word[start] != board[x][y])
            return false;

        visited[x][y] = true;

        //search all neighbours
        bool found = visit(board, word, start + 1, x + 1, y, n, m, visited) 
                  || visit(board, word, start + 1, x - 1, y, n, m, visited)
                  || visit(board, word, start + 1, x, y + 1, n, m, visited) 
                  || visit(board, word, start + 1, x, y - 1, n, m, visited);

        //backtrack
        visited[x][y] = false;
        
        //return if the word was found starting from the current cell
        return found;
    }


public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        //array to keep track of visited positions
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        //convert the word to a char array
        vector<char> wordChar(word.begin(), word.end());

        //trivial solution
        if(wordChar.size() > n * m)
            return false;

        //array to keep track of the frequency of each character
        vector<int> count(256, 0);

        //count the occurences
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                count[board[i][j]]++;

        //adjust the order of the characters in the wordChar array based on their frequency
        //to optimize the search
        int len = wordChar.size();
        for(int i = 0; i < len / 2; i++){
            if(count[wordChar[i]] > count[wordChar[len - 1 - i]]){
                for(int j = 0; j < len / 2; j++){
                    char temp =  wordChar[j];
                    wordChar[j] = wordChar[len - 1 - j];
                    wordChar[len - 1 - j] = temp;
                }
                //reverse(wordChar.begin(), wordChar.end());
                break;
            }
        }

        //decrease counts of charactes in the word from the board
        for(char c : wordChar){
            //if there are more occurences of a char in the word than on the board return false
            if( --count[c] < 0)
                return false;
        }

        //start searching
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visit(board, wordChar, 0, i, j, n, m, visited))
                    return true;
            }
        }

        return false;
    }
};
