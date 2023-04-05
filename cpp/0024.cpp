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
    ListNode* swapPairs(ListNode* head) {
        ListNode fake;
        ListNode* index;

        fake.next = head;
        index = &fake;

        while (index->next && index->next->next) {
            ListNode* tmp = index->next;
            index->next = index->next->next;
            tmp->next = index->next->next;
            index->next->next = tmp;

            index = index->next->next;
        }

        return fake.next;
    }
};
