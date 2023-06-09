/*
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        //credit to jianchao-li
        vector<vector<string>> result;
        vector<string> temp;
        dfs(s, 0, temp, result);
        return result;
    }

    void dfs(string& s, int start, vector<string>& temp, vector<vector<string>>& result){
        int n = s.length();
        if (start == n){
            result.push_back(temp);
        }else{
            for (int i = start; i < n; i++){
                if (isPalindrome(s, start, i)){
                    temp.push_back(s.substr(start, i - start +1));
                    dfs(s, i+1, temp, result);
                    temp.pop_back();
                }
            }
        }
    }

    bool isPalindrome(string& s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
};