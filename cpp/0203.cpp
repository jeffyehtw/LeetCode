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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode fake;
        ListNode* index = &fake;
        
        while (head) {
            if (head->val != val) {
                index->next = new ListNode(head->val);
                index = index->next;
            }
            head = head->next;
        }

        return fake.next;
    }
};
