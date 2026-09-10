/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        int count=0;
        pair<int,int>dfs(TreeNode *node){
            if(!node)return {0,0};
            auto[left,leftcnt]=dfs(node->left);
            auto[right,rightcnt]=dfs(node->right);
            int total=node->val+left+right;
            int totalCnt=1+leftcnt+rightcnt;
            if(total/totalCnt==node->val){
                count++;
            }
            return {total,totalCnt};
        }
        
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};