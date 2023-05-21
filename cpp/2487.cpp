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
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        ListNode fake;
        ListNode* idx = &fake;

        while (head) {
            while (!v.empty() && v.back() < head->val) {
                v.pop_back();
            }
            v.push_back(head->val);
            head = head->next;
        }

        for (int i = 0; i < v.size(); i++) {
            idx->next = new ListNode(v[i]);
            idx = idx->next;
        }

        return fake.next;
    }
};
