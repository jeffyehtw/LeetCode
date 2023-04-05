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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = NULL;
    int* left = NULL;
    int* right = NULL;
    int left_len = 0;
    int right_len = 0;
    
    if (root == NULL) {
        *returnSize = 0;
        return ret;
    }
    
    left = preorderTraversal(root->left, &left_len);
    right = preorderTraversal(root->right, &right_len);
    *returnSize = 1 + left_len + right_len;
    ret = malloc(*returnSize * sizeof(int));
    
    ret[0] = root->val;
    if (root->left) {
        memcpy(ret + 1, left, left_len * sizeof(int));    
    }
    if (root->right) {
        memcpy(ret + 1 + left_len, right, right_len * sizeof(int));    
    }
    
    free(left);
    free(right);
    
    return ret;
}