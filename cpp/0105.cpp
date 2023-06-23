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
    TreeNode* build(vector<int>& pre, int pl, int pr, vector<int>& in, int il, int ir) {
        TreeNode* ret = NULL;
        int mid;
        int left;
        int right;

        if (pl > pr) {
            return ret;
        } 

        for (mid = il; (mid <= ir) && (in[mid] != pre[pl]); mid++);
        left = mid - il;
        right = ir - mid;

        ret = new TreeNode(pre[pl]);
        ret->left = build(pre, pl + 1, pl + left, in, il, mid - 1);
        ret->right = build(pre, pl + left + 1, pr, in, mid + 1, ir);

        return ret;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
