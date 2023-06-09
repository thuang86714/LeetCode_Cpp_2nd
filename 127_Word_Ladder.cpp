/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while(!todo.empty()){
            int n = todo.size();
            for(int i = 0; i < n; i++){
                string word = todo.front();
                todo.pop();
                if (word == endWord){
                    return ladder;
                }
                dict.erase(word);//to avoid redundant comparison
                for(int j = 0; j < word.size(); j++){
                    char temp = word[j];
                    for(int k = 0; k < 26; k++){//going to traverse 26 alphabet
                        word[j] = 'a' + k;
                        if(dict.find(word) != dict.end()){
                            todo.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = temp;
                }
            }
            ladder++;
        }
        return 0;
    }
};