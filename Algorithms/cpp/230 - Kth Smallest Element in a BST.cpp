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
    int kthSmallest(TreeNode* root, int k) {
        // var
        vector<int> res;
        
        helper(root, res, k);
        
        return res[k - 1];
    }
    
    void helper(TreeNode* root, vector<int>& res, int k) {
        if (!root || res.size() >= k)
            return;
        
        helper(root->left, res, k);
        res.push_back(root->val);
        helper(root->right, res, k);
    }
};