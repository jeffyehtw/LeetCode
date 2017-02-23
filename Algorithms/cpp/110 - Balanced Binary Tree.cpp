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
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
            
        cout << height(root) << endl;
        
        traversal(root);
            
        return result;
    }
    
    void traversal(TreeNode* root) {
        if (!root)
            return;
        if (!root->left && !root->right)
            return;
            
        traversal(root->left);
        traversal(root->right);
            
        int left = root->left ? height(root->left) : 0;
        int right = root->right ? height(root->right) : 0;
        
        if (abs(left - right) > 1)
            result = false;
    }
    
    int height(TreeNode* root) {
        if (!root)
            return 0;
        return max(height(root->left), height(root->right))  + 1;
    }
    
    // var
    bool result = true;
};