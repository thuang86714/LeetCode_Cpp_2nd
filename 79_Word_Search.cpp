/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
Example:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(backtrack(board, word, i, j)){
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int i, int j){
        if(!word.size())return false;//base case 1

        if(i < 0|| j < 0 || i >= board.size(); j >= board[0].size() || board[i][j] != word[0]){
            return false;
            //base case 2
        }
        char temp = board[i][j];
        board[i][j] = '*';//or any other char to mark as visited
        string s = word.substr(1);
        bool result = backtrack(board, s, i+1, j) || backtrack(board, s, i-1, j) || backtrack(board, s, i, j-1) || backtrack(board, s, i, j+1);
        board[i][j] = temp;
        return result; 
    }
};