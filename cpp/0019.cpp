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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode fake;
        ListNode* slow = &fake;
        ListNode* fast = &fake;
        ListNode* prev = &fake;

        fake.next = head;        

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        prev->next = slow->next;

        return fake.next;
    }
};
