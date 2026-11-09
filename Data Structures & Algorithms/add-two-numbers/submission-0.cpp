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

        while (l != nullptr && r != nullptr) {
            int dig = (l->val + r->val + c) % 10;
            c = (l->val + r->val + c) / 10;
            ListNode* curr = new ListNode(dig);
            dummy->next = curr;
            dummy=dummy->next;
            l = l->next;
            r = r->next;
        }
        

        while (l != nullptr) {
            int dig = (l->val + c) % 10;
            c = (l->val + c) / 10;
            ListNode* curr = new ListNode(dig);
            dummy->next = curr;
            dummy=dummy->next;
            l = l->next;
        }
        while (r != nullptr) {
            int dig = (r->val + c) % 10;
            c = (r->val + c) / 10;
            ListNode* curr = new ListNode(dig);
            dummy->next = curr;
            dummy=dummy->next;
            r = r->next;
        }
        if(c!=0){
            dummy->next=new ListNode(c);
        }

        return ans.next;
    }
};
