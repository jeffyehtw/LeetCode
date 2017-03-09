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
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root)
            return vector<int>();
        
        // var
        vector<int> result;
        
        traversal(root);
        
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second == MAX)
                result.push_back(it->first);
        }
        
        return result;
    }
    
    int traversal(TreeNode* root) {
        if (!root)
            return 0;
            
        // var
        int left = traversal(root->left);
        int right = traversal(root->right);
        int sum = left + right + root->val;
        
        if (m.find(sum) == m.end())
            m[sum] = 1;
        else {
            m[sum]++;
            MAX = max(MAX, m[sum]);
        }
        
        return sum;
    }
    
    // var
    map<int, int> m;
    int MAX = 1;
};