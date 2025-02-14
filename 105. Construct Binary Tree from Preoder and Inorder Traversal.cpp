/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/


//Complexity: O(n) - time, O(n) - space
class Solution {
private:
    int preorderIndex;
    unordered_map<int, int> map;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //map each value from inorder to its position
        for(int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        preorderIndex = 0;
        return build(preorder, 0, inorder.size() - 1);
    }

private:
//instead of deleting from preorder and creating new vectors from inorder for left and right
//subtrees we will use a map(value:postion) and to indexes to determine with wich values
//of the inorder traversal we are working
    TreeNode* build(vector<int>& preorder, int start, int end){

        if(start > end) return NULL;
        
        //create root
        TreeNode* root = new TreeNode(preorder[preorderIndex]);
        preorderIndex++;

        //determine how to split the inorder traversal
        int mid = map[root->val];
        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);

        return root;
    }
};
