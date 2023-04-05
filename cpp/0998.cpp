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
    TreeNode* _construct(vector<int>& nums, int left, int right) {
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

        ret->left = _construct(nums, left, idx - 1);
        ret->right = _construct(nums, idx + 1, right);

        return ret;
    }
    void _destruct(TreeNode* root, vector<int>& nums) {
        if (root == NULL) {
            return;
        }
        _destruct(root->left, nums);
        nums.push_back(root->val);
        _destruct(root->right, nums);
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> arr;

        if (root == NULL) {
            return NULL;
        }

        _destruct(root, arr);
        arr.push_back(val);
        return _construct(arr, 0, arr.size() - 1);
    }
};
