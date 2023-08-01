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
    vector<TreeNode*> lbound;
    vector<TreeNode*> rbound;
    vector<TreeNode*> leafs;
    bool leaf(TreeNode* root) {
        if (root == NULL) {
            return false;
        } else {
            return !(root->left || root->right);
        }
    }
    void left(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        lbound.push_back(root);
        if (root->left) {
            left(root->left);
        } else {
            left(root->right);
        }
    }
    void right(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        rbound.push_back(root);
        if (root->right) {
            right(root->right);
        } else {
            right(root->left);
        }
    }
    void traverse(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        if (leaf(root)) {
            leafs.push_back(root);
        }
        traverse(root->left, level + 1);
        traverse(root->right, level + 1);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ret;
        vector<TreeNode*> tmp;

        if (root == NULL) {
            return ret;
        }

        tmp.push_back(root);
        if (root->left) {
            left(root->left);
            tmp.insert(tmp.end(), lbound.begin(), lbound.end());
        }
        traverse(root, 0);
        if (tmp.back() == leafs.front()) {
            tmp.pop_back();
        }
        tmp.insert(tmp.end(), leafs.begin(), leafs.end());
        if (root->right) {
            right(root->right);
            reverse(rbound.begin(), rbound.end());
            if (tmp.back() == rbound.front()) {
                tmp.pop_back();
            }
            tmp.insert(tmp.end(), rbound.begin(), rbound.end());
        }
        for (int i = 0; i < tmp.size(); i++) {
            ret.push_back(tmp[i]->val);
        }
        
        return ret;
    }
};
