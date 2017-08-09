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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // var
        TreeNode* root = new TreeNode(0);
        
        if (!t1 && !t2)
            return NULL;
        else if (bool(t1) ^ bool(t2))
            return t1 ? t1 : t2;
        
        root->val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
        
        if (t1->left && t2->left)
            root->left = mergeTrees(t1->left, t2->left);
        else if (t1->left || t2->left)
            root->left = t1->left ? t1->left : t2->left;
        
        if (t1->right && t2->right)
            root->right = mergeTrees(t1->right, t2->right);
        else if (t1->right || t2->right)
            root->right = t1->right ? t1->right : t2->right;
        
        return root;
    }
};