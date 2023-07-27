/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //edge case1: strs[i] == 0;
        //credit to jianchao li
        //in this case(only contains lower case-->range is small), we may further improve TC by counting sort 
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for(string s:strs){
            string temp = s;
            //words are anagram should have the same sorting result
            sort(temp.begin(), temp.end());
            map[temp].push_back(s);
        }
        for(auto m:map){
            result.push_back(m.second);//m.second is vector<string>
        }
        return result;
    }
};