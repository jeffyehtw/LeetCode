/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    vector<pair<TreeNode*, int>> nodes;
    void traversal(TreeNode* root, int idx) {
        if (root == NULL) {
            return;
        }
        traversal(root->left, (idx << 1));
        nodes.push_back(make_pair(root, idx));
        traversal(root->right, (idx << 1) + 1);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int idxp = -1;
        int idxq = -1;

        traversal(root, 1);
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i].first->val == p->val) {
                idxp = nodes[i].second;
            } else if (nodes[i].first->val == q->val) {
                idxq = nodes[i].second;
            }
        }
        while (idxp != idxq) {
            if (idxp > idxq) {
                idxp >>= 1;
            } else {
                idxq >>= 1;
            }
        }
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i].second == idxp) {
                return nodes[i].first;
            }
        }

        return NULL;
    }
};
