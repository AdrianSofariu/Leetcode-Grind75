/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer,
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work.
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 10^4].
-1000 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//This problem can be solved either using a dfs/bfs approach.
//Complexity: O(n) time, O(n) space (for both variants)

//DFS
class Codec {

private:

    void serializeUtil(TreeNode* root, string& ans){
        if(root == NULL){
            ans.append("x,");
            return;
        }
        ans.append(to_string(root->val).append(","));
        serializeUtil(root->left, ans);
        serializeUtil(root->right, ans);
    }

    TreeNode* deserializeUtil(stringstream& s){
        string str;
        getline(s, str, ',');
        if(str == "x")
            return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        root->left = deserializeUtil(s);
        root->right = deserializeUtil(s);
        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        serializeUtil(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        return deserializeUtil(s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


//BFS
class Codec {

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        //Check if the tree is empty
        if(root == NULL){
            return "";
        }

        string ans;
        
        //use queue for bfs
        queue<TreeNode*> q;

        //do bfs
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            //serialize current node
            if(current == NULL)
                ans.append("x,");
            else
                ans.append(to_string(current->val).append(","));

            //enqueue children
            if(current != NULL){
                q.push(current->left);
                q.push(current->right);
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.size() == 0){
            return nullptr;
        }

        //use a stringstream to tokenize the data
        stringstream s(data);
        string str;

        //read root
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));

        //reconstruct the tree using bfs
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            //dequeue the first node
            TreeNode* current = q.front();
            q.pop();

            //read value of left child
            getline(s,str,',');
            if(str == "x")
                current->left = NULL;
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                current->left = leftNode;
                q.push(leftNode);
            }

            //read value of right child
            getline(s,str,',');
            if(str == "x")
                current->right = NULL;
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                current->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
