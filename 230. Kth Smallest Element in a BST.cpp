/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1


Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 
Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104

*/
//Complexity: O(n) - time, O(1) -space
//It is better to sacrifice some execution time instead of doing a morris traversal
//that will leave the tree in a deformed state for a second traversal

//The tree can be modified so that each node stores the number of nodes with a value less than it which will improve performance
//and will allow a recursive approach to be the best if the compiler is optimised for tail recursion

//In this situation it seems morris and iterative inorder perform roughly the same with the caveat that morris trades space for time and iterative inorder does the opposite.

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        int ans = -1;
        TreeNode* current = root;
        while(current != NULL){
            //if no left subtree
            if(current->left == NULL){

                //visit and go right
                k--;
                if(k == 0) ans = current->val;
                current = current->right;
            }
            else{

                //find inorder predecessor
                TreeNode* prev = current->left;
                while(prev->right != NULL && prev->right != current)
                    prev = prev->right;

                //link to current and go to next node
                if(prev->right == NULL){
                    prev->right = current;
                    current = current->left;
                }
                //unlink
                else{
                    prev->right = NULL;
                    k--;
                    if(k == 0) ans = current->val;
                    current = current->right;
                }
            }
        }

        return ans;
    }
};
