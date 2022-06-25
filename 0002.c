/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* index = head;
    
    while (l1 != NULL || l2 != NULL) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        index->next = malloc(sizeof(struct ListNode));
        index = index->next;
        carry = sum / 10;
        index->val = sum % 10;
        index->next = NULL;
    }
    
    if (carry > 0) {
        index->next = malloc(sizeof(struct ListNode));
        index = index->next;
        index->val = carry;
        index->next = NULL;
    }
    
    return head->next;
}