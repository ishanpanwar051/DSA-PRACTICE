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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev =&dummy;

        while(true){

            ListNode* Kth = groupPrev;
            for(int i=0;i<k && Kth;i++) 
            Kth =Kth->next;

            if(!Kth) break;


            ListNode*  groupNext = Kth->next;

            ListNode*prev=groupNext;
            ListNode* curr =groupPrev->next;

            while(curr != groupNext){
                ListNode* temp = curr->next;
                curr->next= prev;
                prev= curr;
                curr =temp;

            }

            ListNode* temp =groupPrev->next;
            groupPrev->next =Kth;
            groupPrev = temp;
        }
        return dummy.next;
    }
};