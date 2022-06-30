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
    int countNodes(TreeNode* root) {
        // var
        int left = depth(true, root);
        int right = depth(false, root);
        
        if (left == right)
            return (1 << left) - 1;
        else 
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int depth(bool dir, TreeNode* root) {
        if (!root)
            return 0;
        
        // var
        int result = 0;
        
        while (root) {
            result++;
            root = dir ? root->left : root->right;
        }
        return result;
    }
};