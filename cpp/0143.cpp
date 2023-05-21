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
    void reorderList(ListNode* head) {
        ListNode* idx = head;

        while (idx) {
            ListNode* tmp = idx;

            while (tmp && tmp->next && tmp->next->next) {
                tmp = tmp->next;
            }
            if (idx == tmp) {
                return;
            }
            tmp->next->next = idx->next;
            idx->next = tmp->next;
            tmp->next = NULL;

            if (idx) {
                idx = idx->next;
            }
            if (idx) {
                idx = idx->next;
            }
        }
    }
};
