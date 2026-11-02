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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head->next==nullptr || head==nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 1;
        int t = 0;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            count++;
            fast = fast->next->next;
        }

        if (fast->next == nullptr) {
            t = count * 2 - 1;
        }

        else {
            t = count * 2;
        }

        int target = t - n + 1;
        int i = 1;
        if(target==1){
            return head->next;
        }

        ListNode* curr = head;
        ListNode* prev=nullptr;
        while (i < target) {
            prev=curr;
            curr = curr->next;
            i++;
        }


        prev->next=curr->next;
        return head;
    }
};
