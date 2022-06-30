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
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        
        // var
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);
        
        return helper(root, 0, sum) + left + right;
    }
    
    int helper(TreeNode* root, int sum, int target) {
        if (!root)
            return 0;
            
        sum += root->val;
        
        // var
        int left = helper(root->left, sum, target);
        int right = helper(root->right, sum, target);
        
        return (sum == target) + left + right;
    }
};