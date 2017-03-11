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
        traversal(root);
        return result[k - 1];
    }
    
    void traversal(TreeNode* root) {
        if (!root)
            return;
        
        traversal(root->left);
        result.push_back(root->val);
        traversal(root->right);
    }
    
    // var
    vector<int> result;
};