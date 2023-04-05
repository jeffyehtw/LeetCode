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
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
private:
    int sum = 0;
    void traversal(TreeNode* root) {
        if (!root)
            return;
        
        if (root->right)
            traversal(root->right);
        
        sum += root->val;
        root->val = sum;
        
        if (root->left)
            traversal(root->left);
    }
};