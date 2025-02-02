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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* l = new ListNode(0);
        ListNode* elem = l;

        while (list1 != nullptr and list2 != nullptr) {
            if (list1->val < list2->val) {
                elem->next = list1;
                list1 = list1->next;
            }
            else {
                elem->next = list2;
                list2 = list2->next;
            }
            elem = elem->next;
        }

        if (list1 != nullptr) elem->next = list1;
        else if (list2 != nullptr) elem->next = list2;

        return l->next;
    }
};