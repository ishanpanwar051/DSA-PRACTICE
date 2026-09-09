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

ListNode* reverseList(ListNode*head){
   ListNode* prev  = nullptr;
   ListNode* curr = head;
   while(curr != nullptr){
    ListNode* newNode =curr->next;
    curr->next= prev  ;
    prev  =curr;
    curr= newNode;
   }
   return prev;
}

    bool isPalindrome(ListNode* head) {
   if(head == nullptr || head->next == nullptr){
    return true;
   }
   ListNode* slow = head;
   ListNode*  fast = head;

   while(fast ->next != NULL && fast ->next->next !=NULL){
    slow = slow->next;
    fast  = fast->next->next;
   }
  ListNode* second_half  = reverseList(slow->next);
  ListNode* p1 = head;;
  ListNode* p2 = second_half;
  while(p2 != nullptr){
    if(p1->val != p2->val){
        return false;


    }
    p1  = p1->next;
    p2 = p2->next;
  }

return true;
            
    }
};
