/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* index = head;
    
    head->val = 0;
    head->next = NULL;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            index->next = malloc(sizeof(struct ListNode));
            index = index->next;
            index->val = list1->val;
            index->next = NULL;
            list1 = list1->next;
        }
        else {
            index->next = malloc(sizeof(struct ListNode));
            index = index->next;
            index->val = list2->val;
            index->next = NULL;
            list2 = list2->next;
        }
    }
    
    while (list1 != NULL) {
        index->next = malloc(sizeof(struct ListNode));
        index = index->next;
        index->val = list1->val;
        index->next = NULL;
        list1 = list1->next;
    }
    while (list2 != NULL) {
        index->next = malloc(sizeof(struct ListNode));
        index = index->next;
        index->val = list2->val;
        index->next = NULL;
        list2 = list2->next;
    }
    
    return head->next;
}