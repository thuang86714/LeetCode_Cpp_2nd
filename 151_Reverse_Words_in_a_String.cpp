/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/
class Solution {
public:
    string reverseWords(string s) {
        string result;
        vector<string> list;
        string temp1 = "", temp2 = " ";
        for(int j = 0; j < s.size(); j++){
            if(s[j] != ' '){
                temp1 += s[j];
            }else{
                if(temp1.size() > 0){
                    list.push_back(temp1);
                    temp1 = "";
                }
            }
            if(j == s.size()-1 && temp1.size() > 0){
                list.push_back(temp1);
            }
        }
        
        for(int i = list.size()-1; i >= 0; i--){
            if(i == 0){
                result += list[i];
            }else{
                list[i] += temp2;
                result += list[i];
            }
        }
        return result;
    }
};

//credit to hiepit, SC O(1)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0, i = 0, n = s.size();
        while (i < n) {
            while (i < n && s[i] != ' ')
                s[r++] = s[i++];

            if (l < r) { // if we can find a non-empty word then
                reverse(s.begin() + l, s.begin() + r); // reverse current word
                if (r == n) break;
                s[r++] = ' '; // set empty space
                l = r;
            }
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
        if (r > 0 && s[r-1] == ' ') --r; // skip last empty character if have
        s.resize(r);
        return s;
    }
};