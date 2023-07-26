/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //edge case1: s.size()==1
        //credit to __himanshu_mehra
        /*
        Time complexity:O(|str1|+|str2|).
        Space complexity:O(Number of different characters).
        */
        if(s.size() == 1)return true;
        unordered_map<char, char>s_map, t_map;
        for(int i = 0; i < s.size(); i++){
            if(s_map[s[i]] && s_map[s[i]] != t[i])return false;
            if(t_map[t[i]] && t_map[t[i]] != s[i])return false;
            s_map[s[i]] = t[i];
            t_map[t[i]] = s[i];
        }
        return true;
    }
};