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
private:
    int length(ListNode* head) {
        int ret = 0;
        while (head) {
            ret++;
            head = head->next;
        }
        return ret;
    }
    ListNode* shiftOne(ListNode* head) {
        ListNode fake;
        ListNode* index = head;

        if (head == NULL) {
            return NULL;
        } else if (head && head->next == NULL) {
            return head;
        }

        fake.next = head;
        
        /* make loop */
        while (index && index->next) {
            index = index->next;
        }
        index->next = fake.next;
        fake.next = index;

        index = head;
        while (index && index->next != fake.next) {
            index = index->next;
        }
        index->next = NULL;

        return fake.next;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = length(head);

        if (len == 0) {
            return NULL;
        }

        for (int i = 0; i < k % len; i++) {
            head = shiftOne(head);
        }
        return head;
    }
};
