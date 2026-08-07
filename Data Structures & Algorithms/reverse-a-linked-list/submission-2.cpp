class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // Base case: if list is empty or only 1 node
        if(head == NULL || head->next == NULL)
        {
            return head;  // Nothing to reverse
        }
        
        // Recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);
        
        // REVERSE: Make the next node point back to current
        head->next->next = head;
        
        // BREAK: Remove forward pointer
        head->next = NULL;
        
        return newHead;
    }
};