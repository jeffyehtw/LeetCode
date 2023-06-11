/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    vector<bool> joined;
    vector<vector<int>> nodes;
    void backtrack(Node* node) {
        if ((node == NULL) || joined[node->val]) {
            return;
        }
        joined[node->val] = true;
        for (int i = 0; i < node->neighbors.size(); i++) {
            nodes[node->val].push_back(node->neighbors[i]->val);
            backtrack(node->neighbors[i]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> umap;

        if (node == NULL) {
            return NULL;
        }

        joined = vector<bool>(101, false);
        nodes = vector<vector<int>>(101, vector<int>());
        backtrack(node);

        for (int i = 0; i < 101; i++) {
            if (!joined[i]) {
                continue;
            }
            umap[i] = new Node(i);
        }
        for (int i = 0; i < 101; i++) {
            if (!joined[i]) {
                continue;
            }
            for (int j = 0; j < nodes[i].size(); j++) {
                umap[i]->neighbors.push_back(umap[nodes[i][j]]);
            }
        }

        return umap[1];
    }
};
