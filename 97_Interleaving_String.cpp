/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //credit to xz2210
        int n1 = (int)s1.size(), n2 = (int)s2.size(), n3 = (int)s3.size(); 
        if(n1 + n2 != n3) return false;
        
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        
        for(int i2 = 1; i2 <= n2; i2++) dp[0][i2] = dp[0][i2 - 1] && s2[i2 - 1] == s3[i2 - 1];
        for(int i1 = 1; i1 <= n1; i1++) dp[i1][0] = dp[i1 - 1][0] && s1[i1 - 1] == s3[i1 - 1];

        for(int i1 = 1; i1 <= n1; i1++){
            for(int i2 = 1; i2 <= n2; i2++){
                dp[i1][i2] = (dp[i1 - 1][i2] && s1[i1 - 1] == s3[i1 + i2 - 1]) || (dp[i1][i2 - 1] && s2[i2 - 1] == s3[i1 + i2 - 1]);
            }
        }
        
        return dp[n1][n2];  
    }
};