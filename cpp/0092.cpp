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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode fake;
        ListNode* index = &fake;
        
        for (int i = 0; head; i++) {
            if (i >= left - 1 && i <= right - 1) {
                ListNode* prev = index->next;
                index->next = new ListNode(head->val);
                index->next->next = prev;

                if (i == right - 1) {
                    while (index->next) {
                        index = index->next;
                    }
                }
            } else {
                index->next = new ListNode(head->val);
                index = index->next;
            }
            head = head->next;
        }
        
        return fake.next;
    }
};
