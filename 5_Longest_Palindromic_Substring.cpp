/*

Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.*/

class Solution {
public:
    string longestPalindrome(string s) {
        //credit to its_vishal_7575
        //two cases: (res.length)%2 ==1 || (res.length)%2 ==0
        int n = s.size();
        int idx = 0, maxLen = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int k = 0; k < n; k++){
            for(int i = 0, j = k; j < n; i++, j++){
                helper(dp, i, j, s);
                if(dp[i][j] == true){
                    if( j - i + 1 > maxLen){
                        idx =i;
                        maxLen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(idx, maxLen);
    }
private:
    bool helper(vector<vector<int>>& dp, int i, int j, string& s){
        if(i == j){
            return dp[i][j] = true;
        }
        if(j - i ==1){
            if(s[i] == s[j]){
                return dp[i][j] = true;
            }else{
                return dp[i][j] = false;
            }
        }
        if(s[i] == s[j] && dp[i+1][j-1] == true){
            return dp[i][j]=true;
        }else{
            return dp[i][j]= false;
        }
    }
};