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
    int _gcd(ListNode* head) {
        if (head && head->next) {
            return gcd(head->val, head->next->val);
        } else {
            return 0;
        }
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode fake;
        ListNode* index = &fake;
        
        while (head && head->next) {
            index->next = new ListNode(head->val);
            index = index->next;
            index->next = new ListNode(_gcd(head));
            index = index->next;
            head = head->next;
        }
        if (head) {
            index->next = new ListNode(head->val);
        }
        
        return fake.next;
    }
};
