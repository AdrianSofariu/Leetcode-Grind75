/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-2^31 <= Node.val <= 2^31 - 1
*/



//solution using morris traversal to avoid adding extra space
//Complexity: O(n) - time, O(1) - space
class Solution {
public:

    bool isValidBST(TreeNode* root) {

        bool valid = true;
        long previous = LONG_MIN;
        TreeNode* curr = root;
        while(curr != NULL){
            //if we don't have a left subtree
            if(curr->left == NULL){
                if(curr->val <= previous)
                    valid = false;
                previous = curr->val;
                curr = curr->right;
            }
            //if we have a left subtree
            else{
                //find inorder predecessor
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right != curr)
                    prev = prev->right;

                //link predecessor to current
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                //undo the link
                else{
                    prev->right = NULL;

                    //compare the value we are adding to the previous one
                    if(curr->val <= previous)
                        valid = false;
                    previous = curr->val;
                    curr = curr->right;
                }
            }
        }
        return valid;
    }
};


//recursive inorder solution then checking if array is ascending
//Compelxity: O(n) - time, O(n) - space
#include <vector>
class Solution {
public:

    std::vector<int> tree;

    void inorder(TreeNode* root){

        if(root == NULL)
            return;

        if(root->left != NULL)
            inorder(root->left);

        tree.push_back(root->val);

        if(root->right != NULL)
            inorder(root->right);
    }


    bool isValidBST(TreeNode* root) {

        if(root == NULL)
            return true;

        inorder(root);

        int len = tree.size();
        if(len < 2)
            return true;
        else{
            int i = 1;
            while(i < len){
                if(tree[i] <= tree[i - 1])
                    return false;
                i++;
            }
        }
        return true;
    }
};

//recursive constraint check
//Complexity: O(n) - time, O(n) - space
class Solution {
public:

    bool helper(TreeNode* node, long min, long max){
        if(node == NULL)
            return true;

        if(node->val <= min || node->val >= max)
            return false;

        return helper(node->left, min, node->val) && helper(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
