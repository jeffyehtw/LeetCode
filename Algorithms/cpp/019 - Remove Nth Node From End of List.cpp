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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // var
        ListNode* new_head = new ListNode(0);
        ListNode* it = new_head;
        ListNode* prev = new_head;
        
        // init
        it->next = head;
        
        while (it) {
            if (find_nth(it, n)) {
                prev->next = it->next;
                return new_head->next;;
            }
            else {
                prev = it;
                it = it->next;
            }
        }
        return new_head->next;
    }
    
    bool find_nth(ListNode* head, int n) {
        for (int i = 0; i < n; i++)
            head = head->next;
        return head == NULL;
    }
};