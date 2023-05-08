/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int _max(TreeNode* root) {
        int left = 0;
        int right = 0;
        int ret = INT_MIN;

        if (root == NULL) {
            return 0;
        }

        ret = max(ret, root->val);
        left = _max(root->left);
        right = _max(root->right);
        left = (left > 0) ? left : 0;
        right = (right > 0) ? right : 0;
        
        ret += max(left, right);

        return (ret > 0) ? ret : 0;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        int left = 0;
        int right = 0;
        
        if (root == NULL) {
            return 0;
        }
        
        ret = max(ret, root->val);
        if (root->left) {
            ret = max(ret, maxPathSum(root->left));
            left = _max(root->left);
        }
        if (root->right) {
            ret = max(ret, maxPathSum(root->right));
            right = _max(root->right);
        }
        left = (left > 0) ? left : 0;
        right = (right > 0) ? right : 0;
        ret = max(ret, root->val + left + right);
        
        return ret;
    }
};
