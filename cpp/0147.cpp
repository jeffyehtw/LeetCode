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
    ListNode* insertionSortList(ListNode* head) {
        ListNode fake;
        ListNode* idx = head;
        ListNode* prev = NULL;

        fake.next = head;
        while (idx) {
            if ((prev == NULL) || (idx->val >= prev->val)) {
                prev = idx;
                idx = idx->next;
            } else {
                ListNode* pos = &fake;

                while ((pos->next)
                    && (pos->next != idx)
                    && (pos->next->val < idx->val)) {
                    pos = pos->next;
                }
                prev->next = idx->next;
                idx->next = pos->next;
                pos->next = idx;
                idx = prev->next;                
            }
        }

        return fake.next;
    }
};
