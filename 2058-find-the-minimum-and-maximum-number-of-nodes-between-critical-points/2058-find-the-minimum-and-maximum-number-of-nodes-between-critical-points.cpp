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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        int i = 0;
        vector<int> res;
        while(cur->next!= NULL)
        {
            if(prev!=NULL)
            {
                if((prev->val > cur->val && cur->next->val > cur->val)||(prev->val < cur->val && cur->next->val < cur->val))res.push_back(i);
            }
            i++;
            prev = cur;
            cur = cur->next;
        }

        if(res.size()<2)return {-1,-1};
        int n = res.size();
        int mnd = INT_MAX;
        for(int  i = 0;i<n-1;i++)
        {
            mnd = min(mnd, res[i+1] - res[i]);
        }
        return {mnd,res[n-1] - res[0]};
    }
};