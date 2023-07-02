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
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //credit to almighty jianchao-li
        //dfs
        //amortized TC O(m*n), since each position on the grid will be visited for at most once.
        int m = grid.size(), n = grid[0].size();
        int island = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    island++;
                    recur(grid, i, j);
                }
            }
        }
        return island;
    }
    void recur(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0|| i >= grid.size()|| j >= grid[0].size() || grid[i][j] == '0')return;
        grid[i][j] = '0';
        recur(grid, i + 1, j);
        recur(grid, i - 1, j);
        recur(grid, i, j + 1);
        recur(grid, i, j - 1);
    }
};