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
    vector<vector<string>> ret;
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    void travel(TreeNode* root, int level, int* index, int height) {
        if (root == NULL || level > height) {
            return;
        }

        if (root->left) {
            travel(root->left, level + 1, index, height);       
        } else if (level < height) {
            *index = *index + (1 << (height - level)) - 1;
        }
        ret[level - 1][*index] = to_string(root->val);
        *index = *index + 1;
        if (root->right) {
            travel(root->right, level + 1, index, height);       
        } else if (level < height) {
            *index = *index + (1 << (height - level)) - 1;
        }
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = 0;
        int w = 0;
        int index = 0;

        if (root == NULL) {
            return ret;
        }

        h = height(root);
        w = (1 << h) - 1;
        ret = vector<vector<string>>(h, vector<string>(w, ""));
        travel(root, 1, &index, h);

        return ret;
    }
};
