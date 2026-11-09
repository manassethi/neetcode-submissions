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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = l1;
        ListNode* r = l2;
        ListNode ans(-1);
        ListNode* dummy = &ans;
        int c = 0;

        while (l != nullptr || r != nullptr || c != 0) {
            int d1 = (l != nullptr) ? l->val : 0;
            int d2 = (r != nullptr) ? r->val : 0;
            int val = c + d2 + d1;
            int d = val % 10;
            c = val / 10;
            dummy->next = new ListNode(d);
            dummy = dummy->next;
            l = (l != nullptr) ? l->next : nullptr;
            r = (r != nullptr) ? r->next : nullptr;
        }

        return ans.next;
    }
};
