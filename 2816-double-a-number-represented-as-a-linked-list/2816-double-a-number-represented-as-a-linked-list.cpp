class Solution {
public:
    ListNode* doubleIt(ListNode* head) {

        // Reverse
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Double
        curr = prev;
        int carry = 0;

        while (curr != NULL) {
            int sum = curr->val * 2 + carry;

            curr->val = sum % 10;
            carry = sum / 10;

            curr = curr->next;
        }

        // Reverse back
        curr = prev;
        prev = NULL;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Carry ko front mein add karo
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            newNode->next = prev;
            prev = newNode;
        }

        return prev;
    }
};