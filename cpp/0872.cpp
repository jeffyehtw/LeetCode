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
    bool isleaf(TreeNode* root) {
        return (root->left == NULL) && (root->right == NULL);
    }
    void traversal(TreeNode* root, vector<int>& leafs) {
        if (root == NULL) {
            return;
        }

        if (isleaf(root)) {
            leafs.push_back(root->val);
        } else {
            traversal(root->left, leafs);
            traversal(root->right, leafs);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1;
        vector<int> leafs2;

        traversal(root1, leafs1);
        traversal(root2, leafs2);

        if (leafs1.size() != leafs2.size()) {
            return false;
        } else {
            for (int i = 0; i < leafs1.size(); i++) {
                if (leafs1[i] != leafs2[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};
