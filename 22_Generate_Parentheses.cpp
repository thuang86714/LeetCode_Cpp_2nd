/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 */
class Solution{
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp;
        recur(0, 0, temp, result, n);
        return result;
    }
    void recur(int open, int close, string temp, vector<string>& result, int n){
        //3 rules to follow
        //1. only add '(' when open< n
        //2. only add ')' when close < open
        //3. only push temp to result when open = close = n
        if(open == n && close == n){
            result.push_back(temp);
        }else{
            if(open < n){
                recur(open+1, close, temp+'(', result, n);
            }
            if(close < open){
                recur(open, close+1, temp+')', result, n);
            }
        }
        
    }
};