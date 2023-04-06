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
    ListNode* oddEvenList(ListNode* head) {
        ListNode left;
        ListNode right;
        ListNode* l = &left;
        ListNode* r = &right;
        bool even = true;

        if (head == NULL) {
            return NULL;
        }

        while (head) {
            if (even) {
                l->next = new ListNode(head->val);
                l = l->next;
            } else {
                r->next = new ListNode(head->val);
                r = r->next;
            }
            head = head->next;
            even = !even;
        }
        l->next = right.next;

        return left.next;
    }
};
