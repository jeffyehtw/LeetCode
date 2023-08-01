/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node fake(0);
        Node* idx = &fake;
        unordered_map<Node*, int> head_map;
        unordered_map<int, Node*> ret_map;

        for (int i = 0; head != NULL; i++) {
            head_map[head] = i;
            idx->next = new Node(head->val);
            idx = idx->next;
            idx->random = head->random;
            ret_map[i] = idx;
            head = head->next;
        }
        idx = fake.next;
        while (idx != NULL) {
            if (idx->random != NULL) {
                idx->random = ret_map[head_map[idx->random]];
            }
            idx = idx->next;
        }

        return fake.next;
    }
};
