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
    ListNode* reverseList(ListNode* head) {
       vector<int>ans;
       if(!head)return NULL;
       ListNode *temp=head;
       while(temp){
        ans.push_back(temp->val);
        temp=temp->next;
       }
       reverse(ans.begin(),ans.end());
       ListNode *dummy=new ListNode(0);
       ListNode *nayanode=dummy;
       for(int i=0;i<ans.size();i++){
        nayanode->next=new ListNode(ans[i]);
        nayanode=nayanode->next;
       }
       return dummy->next;
    }
};