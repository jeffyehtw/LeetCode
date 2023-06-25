/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_map<Node*, bool> path;

        while (p) {
            path[p] = true;
            p = p->parent;
        }
        while (q) {
            if (path.find(q) != path.end()) {
                return q;
            }
            q = q->parent;
        }

        return NULL;
    }
};
