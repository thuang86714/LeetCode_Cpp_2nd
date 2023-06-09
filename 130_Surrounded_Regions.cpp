/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        /*
        1.the basic idea is that if the region is connected to any 'O' on the sides, it would not be'x'
        2.we also need a sign to mark 'O' that would not be fliped, '#'
        */
        int row = board.size();
        if (row == 0)return;
        int col = board[0].size();

        //Moving over firts and last column
        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0, row, col);
            }
            if(board[i][col-1] == 'O'){
                dfs(board, i, col-1, row, col);
            }
        }

        //Moving over firts and last row
        for(int i = 0; i < col; i++){
            if(board[0][i] == 'O'){
                dfs(board, 0, i, row, col);
            }
            if(board[row-1][i] == 'O'){
                dfs(board, row-1, i, row, col);
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int Cur_row, int Cur_col, int row, int col){
        if(Cur_row < 0 || Cur_col < 0 || Cur_row >= row || Cur_col >= col || board[Cur_row][Cur_col] != 'O' ){
            return;
        }
        board[Cur_row][Cur_col] = '#';
        dfs(board, Cur_row + 1, Cur_col, row, col);
        dfs(board, Cur_row - 1, Cur_col, row, col);
        dfs(board, Cur_row, Cur_col + 1, row, col);
        dfs(board, Cur_row, Cur_col - 1, row, col);
    }
};