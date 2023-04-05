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
    ListNode* partition(ListNode* head, int x) {
        ListNode left;
        ListNode right;
        ListNode* index = head;
        ListNode* l = &left;
        ListNode* r = &right;

        while (index) {
            if (index->val < x) {
                l->next = new ListNode(index->val);
                l = l->next;
            } else {
                r->next = new ListNode(index->val);
                r = r->next;
            }
            index = index->next;
        }
        l->next = right.next;

        return left.next;
    }
};
