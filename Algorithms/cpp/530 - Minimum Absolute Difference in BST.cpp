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
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
    
    void traversal(TreeNode* root) {
        if (!root)
            return;
        
        int left = find_max(root->left);
        int right = find_min(root->right);
        
        if (left > -1) {
            result = min(result, root->val - left);
            traversal(root->left);
        }
        if (right > -1) {
            result = min(result, right - root->val);
            traversal(root->right);
        }
    }
    
    int find_min(TreeNode* root) {
        if (!root)
            return -1;
        
        while (root->left)
            root = root->left;

        return root->val;
    }
    
    int find_max(TreeNode* root) {
        if (!root)
            return -1;
            
        while (root->right)
            root = root->right;
            
        return root->val;
    }
    
    // var
    int result = INT_MAX;
};