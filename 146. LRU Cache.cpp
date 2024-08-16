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
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.
*/

class Node{
public:
    int key, value;
    shared_ptr<Node> prev, next;

    Node(int key, int value) : key(key), value(value) {}
};

class LRUCache {
public:

    //We will use a dll and a hashmap to solve this problem
    //Each time we acces a node we will move it after the mock head of the dll
    //Each time a node needs to be removed, the last node before the mock tail will be removed
    //To acces nodes in O(1), we will keep a map with keys and addresses

    

    //build empty dll
    LRUCache(int capacity) : capacity(capacity) {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        //get address of the node
        const auto it = keyNodeMap.find(key);

        //if found, return the value and move after head
        if(it != keyNodeMap.end())
        {
            shared_ptr<Node> node = it->second;
            //remove from its position
            node->prev->next = node->next;
            node->next->prev = node->prev;

            //add to head
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;

            //return value
            return node->value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        //search the node
        const auto it = keyNodeMap.find(key);

        //if found, update value and position
        if(it != keyNodeMap.end())
        {
            shared_ptr<Node> node = it->second;
            node->value = value;

            //remove node
            node->prev->next = node->next;
            node->next->prev = node->prev;

            //add after head
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;
            return;
        }

        //if not found, check capacity
        if(keyNodeMap.size() == capacity)
        {
            shared_ptr<Node> last = tail->prev;
            keyNodeMap.erase(last->key);

            //remove least recently used node
            last->prev->next = last->next;
            last->next->prev = last->prev;
        }

        //move the node after the head
        shared_ptr<Node> node = make_shared<Node>(key, value);
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;

        //add to map
        keyNodeMap[key] = node;
    }

private:
    const int capacity;
    unordered_map<int, shared_ptr<Node>> keyNodeMap;
    shared_ptr<Node> head = make_shared<Node>(-1,-1);
    shared_ptr<Node> tail = make_shared<Node>(-1,-1);
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
