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
    TreeNode* build(
        vector<int>& pre, 
        int prel, 
        int prer, 
        vector<int>& post, 
        int postl, 
        int postr) {
        int mid;
        int left;
        int right;
        TreeNode* ret = NULL;

        if (prel > prer) {
            return ret;
        } else if (prel == prer) {
            ret = new TreeNode(pre[prel]);
            return ret;
        }

        for (mid = postl; mid <= postr; mid++) {
            if (pre[prel + 1] == post[mid]) {
                break;
            }
        }
        left = mid - postl + 1;
        right = postr - 1 - mid;

        ret = new TreeNode(pre[prel]);
        ret->left = build(pre, prel + 1, prel + left, post, postl, postl + left - 1);
        ret->right = build(pre, prel + 1 + left, prer, post, postl + left, postr - 1);

        return ret;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
