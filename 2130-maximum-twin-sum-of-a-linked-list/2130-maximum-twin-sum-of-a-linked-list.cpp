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
    int pairSum(ListNode* head) 
    {
        vector<int> temp;
        while(head!=NULL)
        {
            temp.push_back(head->val);
            head=head->next;
        }
        int r = temp.size()-1;
        int l = 0;
        int ans = INT_MIN;
        while(l<r)
        {
            ans = max(ans,temp[l]+temp[r]);
            l++;
            r--;
        }
        return ans;
    }
//please upvote...
};