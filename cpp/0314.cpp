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
    vector<vector<int>> ret;
    unordered_map<int, int> umap;
    void traverse(TreeNode* root, int idx) {
        queue<pair<TreeNode*, int>> q;

        if (root == NULL) {
            return;
        }

        q.push({ root, 0 });
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                pair<TreeNode*, int> cur = q.front();

                if (cur.first == NULL) {
                    q.pop();
                    continue;
                }
                if (umap.find(cur.second) == umap.end()) {
                    ret.push_back({ cur.first->val });
                    umap[cur.second] = ret.size() - 1;
                } else {
                    ret[umap[cur.second]].push_back(cur.first->val);
                }
                q.push({ cur.first->left, cur.second - 1 });
                q.push({ cur.first->right, cur.second + 1 });
                q.pop();
            }
        }
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        traverse(root, 0);
        for (auto it = umap.begin(); it != umap.end(); it++) {
            ret[it->second].push_back(it->first);
        }
        sort(ret.begin(), ret.end(), [](vector<int>& a, vector<int>& b) {
            return a.back() < b.back();
        });
        for (int i = 0; i < ret.size(); i++) {
            ret[i].pop_back();
        }
        return ret;
    }
};
