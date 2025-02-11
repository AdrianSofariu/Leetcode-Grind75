/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

*/

//Complexity: O(n) - time, O(n) - space

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        queue<TreeNode*> q;

        if(root == NULL)
            return traversal;

        q.push(root);
        while(!q.empty()){

            int level = q.size();
            vector<int> aux;
            TreeNode* curr;

            //go through all nodes on a level and add their children to the queue
            for(int i = 0; i < level; i++){
                curr = q.front();
                q.pop();
                //add current node to level
                aux.push_back(curr->val);

                //add children to queue
                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }

            //add the level to the final result
            traversal.push_back(aux);
        }

        return traversal;
    }
};
