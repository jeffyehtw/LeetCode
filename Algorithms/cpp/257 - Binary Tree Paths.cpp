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
        if (!root)
            return result;
            
        traversal(root->left, to_string(root->val));
        traversal(root->right, to_string(root->val));
        
        if (result.size() == 0)
            return vector<string>{ "1" };
            
        return result;
    }
    
    void traversal(TreeNode* root, string path) {
        if (!root)
            return;
        
        if (!root->left && !root->right)
            result.push_back(path + "->" + to_string(root->val));
        
        path += "->" + to_string(root->val);
        
        if (root->left)
            traversal(root->left, path);
        if (root->right)
            traversal(root->right, path);
    }
    
    // var
    vector<string> result;
};