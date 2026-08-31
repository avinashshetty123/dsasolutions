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
        if(!head||!head->next||!head->next){
            return {-1,-1};
        }
        ListNode *prev=head;
        ListNode *curr=head->next;
        int currIdx=1;
        int first=-1;
        int second=-1;
        int mini=INT_MAX;
        while(curr->next!=NULL)
        {
            bool ismaxi=(curr->val>prev->val)&&(curr->val>curr->next->val);
            bool ismini=(curr->val<prev->val)&&(curr->val<curr->next->val);
            if(ismaxi||ismini){
                if(first==-1){
                    first=currIdx;
                }else{
                    mini=min(mini,currIdx-second);
                }
                second=currIdx;
            }
            prev=curr;
            curr=curr->next;
            currIdx++;
        }
        if(mini==INT_MAX){
            return {-1,-1};
        }
        return {mini,second-first};
    }
};