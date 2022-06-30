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
    ListNode* swapPairs(ListNode* head) {
        // var
        ListNode* dummy = new ListNode(0);
        ListNode* index = dummy;

        // init
        dummy->next = head;
        
        while (index->next && index->next->next) {
            // var
            ListNode* front = index->next;
            ListNode* back = index->next->next;
            ListNode* tmp = back->next;
            
            index->next = back;
            back->next = front;
            front->next = tmp;
            
            index = index->next->next;
        }
        
        return dummy->next;
    }
};