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
        ListNode result(0);
        ListNode *it = &result;
        
        // add
        while(l1 || l2 || carry) {
            int sum = carry;
            sum += l1 ? l1->val : 0;
            sum += l2 ? l2->val : 0;
            
            carry = sum / 10;
            sum %= 10;
            
            it->next = new ListNode(sum);
  
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            it = it-> next;
        }     
        return result.next;
    }
};