/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nodes;
        vector<int> ret;
        stack<int> st;

        while (head) {
            nodes.push_back(head->val);
            head = head->next;
        }
        ret = vector<int>(nodes.size(), 0);

        for (int i = nodes.size() - 1; i > -1; i--) {
            if (st.empty()) {
                ret[i] = 0;
            } else {
                while (!st.empty() && st.top() <= nodes[i]) {
                    st.pop();
                }
                ret[i] = st.empty() ? 0 : st.top();
            }
            st.push(nodes[i]);
        }

        return ret;
    }
};
