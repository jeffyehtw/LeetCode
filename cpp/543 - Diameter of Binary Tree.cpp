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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        
        // var
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int result = depth(root->left) + depth(root->right);
        
        return max(result, max(left, right));
    }
    
private:
    int depth(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};