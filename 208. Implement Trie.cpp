/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
There are various applications of this data structure, such as autocomplete and spellchecker.

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
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.

*/

class TrieNode{
    public:
        bool endOfWord;
        TrieNode *children[26];

        TrieNode(){
            endOfWord = false;
            for(int i = 0; i < 26; i++)
                children[i] = NULL;
        }

        //check if node contains given letter
        bool contains(char c){
            return (children[c - 'a'] != NULL);
        }

        //get node associated with letter
        TrieNode* get(char c){
            return children[c - 'a'];
        }

        //associate a node to a letter
        void putKey(char c, TrieNode* n){
            children[c - 'a'] = n;
        }


};


class Trie {
private:
    TrieNode* root;

public:

    Trie() {
        root = new TrieNode();
    }

    //destructor
    /*~Trie(){
        clear(root);
    }

    //destructor utility
    void clear(TrieNode* root){
        for(int i = 0; i < 26; i++)
            if(root->children[i] != NULL)
                clear(root->children[i]);
        delete root;
    }*/
    
    //Complexity: O(n) - time
    void insert(string word) {
        int len = word.length();
        TrieNode *cur = root;
        for(int i = 0; i < len; i++){
            if(cur->contains(word[i]) == false){
                cur->putKey(word[i], new TrieNode());
            }

            cur = cur->get(word[i]);
        }
        cur->endOfWord = true;
    }
    
    //Complexity: O(n) - time
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            if(cur->contains(word[i]) == false)
                return false;
            cur = cur->get(word[i]);
        }

        return cur->endOfWord;
    }
    
    //Complexity: O(n) - time
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i = 0; i < prefix.size(); i++){
            if(cur->contains(prefix[i]) == false)
                return false;
            cur = cur->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
