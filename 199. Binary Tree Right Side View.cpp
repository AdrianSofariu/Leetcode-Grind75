/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]


Example 2:
Input: root = [1,null,3]
Output: [1,3]


Example 3:
Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:

    //To solve this we do something akin to a recursvie dfs
    //We start from root with level 0. If the level is equal to the length
    //of the list, we are at a new unexplored level so we add the node to the list.
    //Then we recure for the right and left neighbours.
    //Complexity: O(n) - time, O(h) - stack space (h == height of tree)
    vector<int> ans;

    void recure(TreeNode* root, int level){
        if(root == NULL){
            return;
        }

        if(level == ans.size())
            ans.push_back(root->val);

        recure(root->right, level + 1);
        recure(root->left, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        recure(root, 0);
        return ans;
    }
};
