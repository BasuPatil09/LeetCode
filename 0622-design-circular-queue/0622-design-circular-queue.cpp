class MyCircularQueue {
public:

    int n;
    int sz = 0;

    ListNode* head;
    ListNode* curr;
    ListNode* prev;

    MyCircularQueue(int k) {
        n = k;

        ListNode* h = new ListNode(-1);
        ListNode* temp = h;

        for (int i = 1; i < k; i++) {
            temp->next = new ListNode(-1);
            temp = temp->next;
        }

        temp->next = h;

        head = h;
        curr = head;
        prev = head;
    }

    bool enQueue(int value) {

        if (sz == n)
            return false;

        curr->val = value;
        prev = curr;
        curr = curr->next;
        sz++;

        return true;
    }

    bool deQueue() {

        if (sz == 0)
            return false;

        head->val = -1;
        head = head->next;
        sz--;

        if (sz == 0) {
            curr = head;
            prev = head;
        }

        return true;
    }

    int Front() {
        if (sz == 0)
            return -1;

        return head->val;
    }

    int Rear() {
        if (sz == 0)
            return -1;

        return prev->val;
    }

    bool isEmpty() {
        return sz == 0;
    }

    bool isFull() {
        return sz == n;
    }
};