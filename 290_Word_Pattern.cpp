/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //partial credit to mansi21
        //edge case1: pattern.size() != s.NumofWord();
        //edge case2: pattern[i] != pattern[j], but both try to map to the same word in s

        //stream words in s into vector, since elements in vector are continguous
        vector<string> list;
        string word;//to store streaming
        stringstream iss(s);
        while(iss >> word){
            list.push_back(word);
        }

        //handle edge case1
        if(pattern.size() != list.size())return false;

        //using set to handle edge case2
        unordered_set<string> mapped;
        unordered_map<char, string>m;

        for(int i = 0; i < pattern.size(); i++){
            //take current char in pattern
            char c = pattern[i];
            
            //check if c already in m
            if(m.find(c) != m.end()){
                //check if the string previously mapped to this char c is different from the current string
                if(m[c] != list[i])return false;
            }else{
                //c is not in the map m, but that doesn't mean c's string has not been mapped
                if(mapped.count(list[i]) > 0)return false;

                //otherwise insert c's string into set mapped, and map m
                m[c] = list[i];
                mapped.insert(list[i]);
            }
        }
        return true;
    }
};