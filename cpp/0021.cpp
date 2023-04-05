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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode fake;
        ListNode* index = &fake;
        
        while (list1 != NULL && list2 != NULL) {
            if (list1->val > list2->val) {
                index->next = new ListNode(list2->val);
                index = index->next;
                list2 = list2->next;
            } else {
                index->next = new ListNode(list1->val);
                index = index->next;
                list1 = list1->next;
            }
        }
        while(list1 != NULL) {
            index->next = new ListNode(list1->val);
            index = index->next;
            list1 = list1->next;
        }
        while(list2 != NULL) {
            index->next = new ListNode(list2->val);
            index = index->next;
            list2 = list2->next;
        }

        return fake.next;
    }
};
