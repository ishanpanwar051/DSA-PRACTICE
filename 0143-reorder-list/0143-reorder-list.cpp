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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow =  slow ->next;
            fast = fast->next->next;

        }
       

        ListNode *second_half = slow->next;
        ListNode* curr =second_half;
        slow->next = nullptr; 
        ListNode* prev = nullptr;
    
       while(curr != nullptr){
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr= nextNode;
       }
        ListNode* p1 = head;
        ListNode* p2 = prev;

       while(p2 != nullptr){
        ListNode* a = p1->next;
        ListNode* b= p2->next;
         
         p1->next =p2;
         p2->next =a;

         p1= a;
         p2 = b;

       }

    }
};