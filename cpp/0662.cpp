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
    vector<pair<unsigned int, unsigned int>> vp;
    void traversal(TreeNode* root, int level, unsigned int idx) {
        if (root == NULL) {
            return;
        }

        if (level > vp.size()) {
            vp.push_back(make_pair(idx, idx));
        } else {
            vp[level - 1].first = min(vp[level - 1].first, idx);
            vp[level - 1].second = max(vp[level - 1].second, idx);
        }
        traversal(root->left, level + 1, idx << 1);
        traversal(root->right, level + 1, (idx << 1) + 1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned int ret = 0;

        if (root == NULL) {
            return ret;
        }

        traversal(root, 1, 1);
        for (int i = 0; i < vp.size(); i++) {
            ret = max(ret, vp[i].second - vp[i].first + 1);
        }

        return ret;
    }
};
