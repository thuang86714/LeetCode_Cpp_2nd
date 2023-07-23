/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True*/
//credit to alexander
class Trie {
public:
    Trie() {}
    
    void insert(string word) {
        Trie* node = this;
        for (char c:word){
            c -= 'a';
            if (!node->next[c]){node->next[c] = new Trie();}
            node = node->next[c];
        }
        node->isword = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c : word){
            c -= 'a';
            if(!node->next[c]){return false;}
            node = node->next[c];
        }
        return node->isword;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c : prefix){
            c -= 'a';
            if(!node->next[c]){return false;}
            node = node->next[c];
        }
        return true;
    }
private:
    map<char, Trie*> next;
    bool isword = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */