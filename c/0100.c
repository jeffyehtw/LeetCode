/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    bool p1 = (p == NULL);
    bool p2 = (q == NULL);
    
    if (p1 && p2) {
        return true;
    }
    else if (!p1 && !p2) {
        return ((p->val == q->val) 
                && isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right));
    }
    else {
        return false;
    }
}