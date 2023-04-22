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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode fake;
        ListNode* idx = head;
        ListNode* prev = &fake;

        fake.next = head;
        while (idx && idx->next) {
            if (idx->val == idx->next->val) {
                ListNode* next = idx->next;

                while (next && idx->val == next->val) {
                    next = next->next;
                }
                prev->next = next;
                idx = next;
            } else {
                prev = idx;
                idx = idx->next;
            }
        }
        
        return fake.next;
    }
};
