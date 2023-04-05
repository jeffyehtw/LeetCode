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
    int max = 0;
    unordered_map<int, int> umap;
    int traversal(TreeNode* root) {
        int sum = 0;

        if (root == NULL) {
            return 0;
        }

        sum = root->val;
        if (root->left) {
            sum += traversal(root->left);
        }
        if (root->right) {
            sum += traversal(root->right);
        }
        if (umap.find(sum) == umap.end()) {
            umap[sum] = 1;
        } else {
            umap[sum]++;
        }
        if (umap[sum] > max) {
            max = umap[sum];
        }

        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ret;
        
        traversal(root);
        for (auto it = umap.begin(); it != umap.end(); it++) {
            if (it->second == max) {
                ret.push_back(it->first);
            }
        }

        return ret;
    }
};
