/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = NULL;
    int* left = NULL;
    int* right = NULL;
    int left_len = 0;
    int right_len = 0;
    
    *returnSize = 0;
    
    if (root == NULL) {
        return ret;    
    }
    
    if (root->left) {
        left = inorderTraversal(root->left, &left_len);
    }
    if (root->right) {
        right = inorderTraversal(root->right, &right_len);
    }
    
    ret = malloc((1 + left_len + right_len) * sizeof(int));
    
    ret[left_len] = root->val;
    if (left) {
        memcpy(ret, left, left_len * sizeof(int));
        free(left);
    }
    if (right) {
        memcpy(ret + left_len + 1, right, right_len * sizeof(int));
        free(right);
    }
    *returnSize = 1 + left_len + right_len;
    
    return ret;
}