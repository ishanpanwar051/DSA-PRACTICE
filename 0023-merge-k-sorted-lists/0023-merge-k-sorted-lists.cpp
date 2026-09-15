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

struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minHeap;

        for(int i=0;i<lists.size();i++){
           if(lists[i] != nullptr){
             minHeap.push(lists[i]);
           }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(!minHeap.empty()){
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next= smallest;
            tail = tail->next;

            if(smallest->next != nullptr){
                minHeap.push(smallest->next);
            }
        }
        return dummy->next;
    }

};