/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode* p1, struct TreeNode* p2) {
    if (!p1 && !p2) {
        return true;
    }
    else if (!p1 || !p2) {
        return false;
    }
    
    if (p1->val != p2->val) {
        return false;
    }
    
    return (isMirror(p1->left, p2->right)
            && isMirror(p1->right, p2->left));
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);    
}