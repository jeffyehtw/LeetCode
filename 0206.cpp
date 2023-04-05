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
    ListNode* reverseList(ListNode* head) {
        ListNode fake;
        ListNode* index;

        while (head) {
            ListNode* prev = fake.next;
            fake.next = new ListNode(head->val);
            fake.next->next = prev;
            head = head->next;
        }

        return fake.next;
    }
};
