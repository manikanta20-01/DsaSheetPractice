

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
         if (head == nullptr) return head;

        ListNode *curr = head;
        int n{};
        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }

        k %= n;
        if (k == 0) return head;

        ListNode* back = head;
        for (int i = 0; i < n - k - 1; i++) back = back->next;

        ListNode *front = back->next;
        back->next = nullptr;

        ListNode *p = front;
        while (p->next != nullptr) p = p->next;

        p->next = head;

        return front;
    }
};