/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/

class Solution {
public:
    const vector<string> keyboard = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"  
    };
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)return {};
        vector<string> result;
        recur(0, result, digits, "");
        return result;
    }
    void recur(int idx, vector<string>& result, string digits, string temp){
        //base case
        if(idx == digits.length()){
            result.push_back(temp);
            return;
        }else{
            for(char c: keyboard[digits[idx]-'0']){
                recur(idx+1, result, digits, temp+c);
            }
        }
    }
};