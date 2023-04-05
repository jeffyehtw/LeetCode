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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // var
        int carry = 0;
        ListNode* prev = NULL;
        ListNode* result = NULL;
        ListNode* r1 = reverse_linked_list(l1);
        ListNode* r2 = reverse_linked_list(l2);
        
        // add
        while (r1 || r2) {
            prev = result;
            result = new ListNode(0);
            result->next = prev;
            
            result->val += carry;
            result->val += r1 ? r1->val : 0;
            result->val += r2 ? r2->val : 0;
            
            carry = result->val / 10;
            result->val %= 10;
            
            r1 = r1 ? r1->next : r1;
            r2 = r2 ? r2->next : r2;
        }
        
        // last
        if (carry > 0) {
            prev = result;
            result = new ListNode(carry);
            result->next = prev;
        }
        return result;
    }
    
    ListNode* reverse_linked_list(ListNode* head) {
        if (!head || !head->next)
            return head;
            
        // var
        ListNode* prev = NULL;
        ListNode* result = NULL;
       
        while (head) {
            prev = result;
            result = new ListNode(head->val);
            result->next = prev;
            head = head->next;
        }
        return result;
    }
};