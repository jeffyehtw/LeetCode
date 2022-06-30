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
    //var
    vector<vector<int>> result;
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return vector<vector<int>>();
            
        traversal(root, vector<int>(), sum);    
        
        return result;
    }
    
    void traversal(TreeNode* root, vector<int> path, int sum) {
        if (!root)
            return;
        
        // init
        path.push_back(root->val);
        
        if (!root->left && !root->right) {
            if (root->val == sum)
                result.push_back(path);
            else
                return;
        }
        
        traversal(root->left, path, sum - root->val);
        traversal(root->right, path, sum - root->val);
    }
};