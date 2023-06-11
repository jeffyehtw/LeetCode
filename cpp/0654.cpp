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
    TreeNode* help(vector<int>& nums, int left, int right) {
        int mid = 0;
        int max = INT_MIN;
        TreeNode* ret = NULL;

        if (left > right) {
            return ret;
        }
        for (int i = left; i <= right; i++) {
            if (nums[i] > max) {
                max = nums[i];
                mid = i;
            }
        }

        ret = new TreeNode(max);
        if (left == right) {
            return ret;
        }

        if (mid > left) {
            ret->left = help(nums, left, mid - 1);
        }
        if (right > mid) {
            ret->right = help(nums, mid + 1, right);
        }

        return ret;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return help(nums, 0, nums.size() - 1);
    }
};
