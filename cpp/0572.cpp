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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (bool(s) != bool(t))
            return false;
        
        return same(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
private:
    bool same(TreeNode* s, TreeNode* t) {
        if (bool(s) != bool(t))
            return false;
        else if (!s && !t)
            return true;
        else if (s->val != t->val)
            return false;
        
        // var
        bool left = same(s->left, t->left);
        bool right = same(s->right, t->right);
        
        return left && right;
    }
};