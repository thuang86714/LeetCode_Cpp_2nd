/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.
*/
class TrieNode{
public:
    bool isEnd = false;
    TrieNode* children[26];
    TrieNode(){
        memset(children, 0, sizeof(children));
    }
};
class WordDictionary {
public:
//credit to duduita
    WordDictionary() {
        
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *node = root;
        for(char c:word){
            if(!node->children[c - 'a']){
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(word, root, 0);
    }
private:
    TrieNode *root = new TrieNode();

    bool helper(string word, TrieNode *node, int pos){
        if(pos == word.size())return node->isEnd;//base case

        if(word[pos] != '.'){
            node = node->children[word[pos] - 'a'];
            // this 'node' before the search is to avoid unnecessary recursion calls (if node is null, the linked list was ended up)
			// we increment our 'pos' by 1, in order to search the next character, if it exists
            return node && helper(word, node, pos+1);
        }

        // if there's a '.', we need to force iteration in all possible cases
        for(int i = 0; i < 26; i++){
            // 'node->children[i]' is here to avoid unnecessary recursion calls (if this node->children[i] is null, the linked list was ended up)
            if(node->children[i] && helper(word, node->children[i], pos+1))return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */