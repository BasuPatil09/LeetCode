class Solution {
    ListNode* curr;

    bool solve(ListNode* head) {
        if (!head) return true;

        bool result = solve(head->next) &&
                      (head->val == curr->val);

        curr = curr->next;
        return result;
    }

public:
    bool isPalindrome(ListNode* head) {
        curr = head;
        return solve(head);
    }
};