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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // var
        int lenA = len(headA);
        int lenB = len(headB);
        int max_len = max(lenA, lenB);
        int min_len = min(lenA, lenB);
        
        if (min_len == 0)
            return NULL;
        
        for (int i = 0; i < max_len - min_len; i++) {
            if (lenA > min_len)
                headA = headA->next;
            if (lenB > min_len)
                headB = headB->next;
        }
        
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
private:
    int len(ListNode *head) {
        int count = 0;
        while (head != NULL) {
            head = head->next;
            count++;
        }
        return count;
    }
};