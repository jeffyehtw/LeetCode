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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* index = head;
        ListNode* prev = head;
        int len = 0;

        while (index) {
            len++;
            index = index->next;
        }

        if (len < 2) {
            return NULL;
        }

        index = head;
        for (int i = 0; i < len / 2; i++) {
            prev = index;
            index = index->next;
        }
        prev->next = index->next;

        return head;
    }
};
