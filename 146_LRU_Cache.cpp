/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/

class LRUCache {
public:
    //credit to ankur_rohilla
    //the functions get & put must each run in avg O(1)
    //doubly linked list work best in the case
    class node{
    public:
        int key;
        int val;
        node *next;
        node *prev;

        node(int key, int val){
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    unordered_map<int, node*>mp;
    int capacity;

    //two dummy nodes to keep track starting and ending point of list  
    node *head = new node(0, 0);
    node *tail = new node(0, 0);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    //function to help a node in the next to head [can say front of our list]
    void insert(node *current){
        current->next = head->next;// adding node in next of head (front of our cache)
        head->next->prev = current;
        head->next = current;
        current->prev = head;
        mp[current->key] = current;//update map accordingly
    }

    // function to remove a node 
    void remove(node *current){
        mp.erase(current->key);
        current->next->prev = current->prev;
        current->prev->next = current->next;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())return -1;

        //if key is present , then update the node and return the value associated with the key
        //to update first we remove the node and then add at start of list with the help of insert function
        node *current = mp[key];
        remove(current);
        insert(current);
        return current->val;
    }
    
    void put(int key, int value) {
        //if key is already present then we have to update it 
       // similiary we first remove and then add node in front with the help of insert helper 
       if(mp.find(key) != mp.end())remove(mp[key]);

       // if size is full then we have to remove the least recently used node
        if(mp.size()==capacity){
            remove(tail->prev);
        }
        insert(new node(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */