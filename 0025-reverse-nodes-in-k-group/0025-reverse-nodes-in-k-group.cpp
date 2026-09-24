class Solution {
private:
    ListNode* reverse(ListNode* behind_of_group, ListNode* head, int k)
    {
        ListNode* current = head;
        ListNode* prev = nullptr;
        int count = k;

        while (count != 0)
        {
            ListNode* aage = current->next;
            current->next = prev;
            prev = current;
            current = aage;
            count--;
        }

        if (behind_of_group)
            behind_of_group->next = prev;

        head->next = current;

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head || k <= 1)
            return head;

        int n = 0;
        ListNode* curr = head;

        while (curr)
        {
            n++;
            curr = curr->next;
        }

        ListNode* new_head = head;
        ListNode* behind_group = nullptr;
        ListNode* current_group_head = head;

        for (int i = 0; i + k <= n; i += k)
        {
            ListNode* reversed_head = reverse(behind_group, current_group_head, k);

            if (i == 0)
                new_head = reversed_head;

            behind_group = current_group_head;
            current_group_head = current_group_head->next;
        }

        return new_head;
    }
};