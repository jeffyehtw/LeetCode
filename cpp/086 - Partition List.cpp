/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // var
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);
        ListNode* l = left;
        ListNode* r = right;
        
        while (head) {
            if (head->val >= x) {
                r->next = head;
                r = r->next;
            }
            else {
                l->next = head;
                l = l->next;
            }
            head = head->next;
        }
        
        r->next = NULL;
        l->next = right->next;
        
        return left->next;
    }
};