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
    vector<int> inorderTraversal(TreeNode* root) {
        // var
        vector<int> left;
        vector<int> right;
        vector<int> result;
        
        if (!root)
            return result;
            
        if (root->left)
            left = inorderTraversal(root->left);
            
        if (root->right)
            right = inorderTraversal(root->right);
            
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(root->val);
        result.insert(result.end(), right.begin(), right.end());
        
        return result;
    }
};