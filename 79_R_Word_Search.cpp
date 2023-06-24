/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //what's the TC? we know branch is 4, how about the depth?
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(recur(board, word, i ,j))return true;
            }
        }
        return false;
    }
    bool recur(vector<vector<char>>& board, string word, int i, int j ){
        //there are 2 base cases
        if(!word.size())return true;//this means we've found all the matches of char till the end
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[0]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        bool result = (recur(board, s, i + 1, j) || recur(board, s, i -1 , j) || recur(board, s, i, j + 1) || recur(board, s, i, j - 1));
        board[i][j] = temp;
        return result;
    }
};