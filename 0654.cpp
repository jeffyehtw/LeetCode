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
    TreeNode* _constructMaximumBinaryTree(vector<int>& nums, int left, int right) {
        int max = -1;
        int idx = -1;
        TreeNode* ret = NULL;

        if (left > right) {
            return ret;
        }

        for (int i = left; i <= right; i++) {
            if (nums[i] > max) {
                max = nums[i];
                idx = i;
            }
        }

        ret = new TreeNode(max);

        ret->left = _constructMaximumBinaryTree(nums, left, idx - 1);
        ret->right = _constructMaximumBinaryTree(nums, idx + 1, right);

        return ret;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return _constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }
};
