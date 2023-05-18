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
    ListNode* getMid(ListNode* head) {
        ListNode* slow;
        ListNode* fast;

        if ((head == NULL) || (head->next == NULL)) {
            return NULL;
        }

        slow = head;
        fast = head->next;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode fake;
        ListNode* idx = &fake;

        while (left && right) {
            if (left->val < right->val) {
                idx->next = left;
                left = left->next;
            } else {
                idx->next = right;
                right = right->next;
            }
            idx = idx->next;
        }
        while (left) {
            idx->next = left;
            idx = idx->next;
            left = left->next;
        }
        while (right) {
            idx->next = right;
            idx = idx->next;
            right = right->next;
        }

        return fake.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode* left;
        ListNode* right;
        ListNode* mid;

        if ((head == NULL) || (head->next == NULL)) {
            return head;
        }

        mid = getMid(head);
        left = head;
        right = mid->next;
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};
