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
    vector<string> binaryTreePaths(TreeNode* root) {
        // var
        vector<string> result;
        
        if (!root)
            return vector<string>();
        if (!root->left && !root->right)
            return vector<string>({ to_string(root->val) });
        if (root->left)
            helper(root->left, to_string(root->val), result);
        if (root->right)
            helper(root->right, to_string(root->val), result);
        
        return result;        
    }
    
    void helper(TreeNode* root, string tmp, vector<string>& r) {
        if (!root->left && !root->right)
            r.push_back(tmp + "->" + to_string(root->val));
        if (root->left)
            helper(root->left, tmp + "->" + to_string(root->val), r);
        if (root->right)
            helper(root->right, tmp + "->" + to_string(root->val), r);
    }
};