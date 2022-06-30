/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
            
        return sum_leaf(root, 0);
    }
    
    int sum_leaf(TreeNode* root, int sum) {
        if (!root)
            return 0;

        // var
        int left = 0;
        int right = 0;
        int result = sum + root->val;
        
        if (!root->left && !root->right)
            return result;
        if (root->left != NULL) {
            left = sum_leaf(root->left, result * 10);
        }
        if (root->right != NULL) {
            right = sum_leaf(root->right, result * 10);
        }
        
        return left + right;
    }
};