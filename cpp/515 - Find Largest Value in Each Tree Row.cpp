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
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return vector<int>();
        
        traversal(root, 0);
        
        return result;
    }
    
    void traversal(TreeNode* root, int level) {
        if (!root)
            return;
        
        if (result.empty() || level >= result.size())
            result.push_back(root->val);
        else
            result[level] = max(result[level], root->val);
            
        traversal(root->left, level + 1);
        traversal(root->right, level + 1);
    }
    
    // var
    vector<int> result;
};