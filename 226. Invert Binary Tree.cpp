/*
Given the root of a binary tree, invert the tree, and return its root.

Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]


Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

//recursive version
//Complexity: O(n) - time, O(n) - space  (if compiler is not optimized for tail recursion)
class Solution {
public:

    void swap(TreeNode* root){
        if(root != NULL){
            TreeNode* left = root->left;
            root->left = root->right;
            root->right = left;
            swap(root->left);
            swap(root->right);
        }
    }

    TreeNode* invertTree(TreeNode* root) {

        swap(root);
        return root;
    }
};

//the practical solution
//Complexity: O(n) - time, O(n) - space
#include <queue>

class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        
        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            //swap nodes
            TreeNode* left = current->left;
            current->left = current->right;
            current->right = left;

            if(current->left != NULL)
                q.push(current->left);

            if(current->right != NULL)
                q.push(current->right);
        }

        return root;
    }
};
