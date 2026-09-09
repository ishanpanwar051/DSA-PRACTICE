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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(head==nullptr || left == right)
       {
        return head;
       }

       ListNode  dummy(0);
       dummy.next = head;
       ListNode*prev = &dummy;
for(int i=1;i<left;i++){
    prev = prev->next;
}

ListNode* curr = prev->next;
ListNode* subPrev= nullptr;

       for(int i=1;i<=right-left+1;i++){
        ListNode* nextNode = curr->next;
        curr->next = subPrev;
        subPrev = curr;
        curr= nextNode;


       }
       prev->next->next = curr;
       prev->next = subPrev;

       return dummy.next;
    }
};