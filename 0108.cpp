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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ret;
        vector<int> left;
        vector<int> right;
        int middle = nums.size() / 2;

        if (nums.size() == 0) {
            return NULL;
        }

        left = vector<int>(nums.begin(), nums.begin() + middle);
        right = vector<int>(nums.begin() + middle + 1, nums.end());

        
        ret = new TreeNode(nums[middle]);
        if (left.size() > 0) {
            ret->left = sortedArrayToBST(left);
        }
        if (right.size() > 0) {
            ret->right = sortedArrayToBST(right);
        }

        return ret;
    }
};
