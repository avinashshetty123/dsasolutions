/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>>ans;
        if(!root)return ans;
      queue<TreeNode *>q;
      q.push(root);
      while(!q.empty()){
        vector<int>st;
        int size=q.size();
        for(int i=0;i<size;i++){

        TreeNode *topi=q.front();
        q.pop();
        st.push_back(topi->val);
        if(topi->left)q.push(topi->left);
        if(topi->right)q.push(topi->right);
    
        }
      ans.push_back(st);
      }
      return ans;
    }
};