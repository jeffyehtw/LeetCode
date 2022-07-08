/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* ret = NULL;
    struct ListNode* prev = NULL;
    
    if (head == NULL) {
        return ret;
    }
    
    while(head) {
        prev = ret;
        ret = malloc(sizeof(struct ListNode));
        ret->val = head->val;
        ret->next = prev;
        head = head->next;
    }
    
    return ret;
}