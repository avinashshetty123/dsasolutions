class Solution {
public:
bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
if(vis[node]==1)return true;
if(vis[node]==2)return false;
vis[node]=1;
for(int i:adj[node]){
    if(dfs(i,adj,vis)){
        return true;
    }
}
vis[node]=2;
return false;

}
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
     vector<vector<int>>adj(n);
     for(auto &p:prerequisites){
        int a=p[0];
        int b=p[1];
        adj[b].push_back(a);
     }
     vector<int>state(n,0);
     for(int i=0;i<n;i++){
        if(dfs(i,adj,state)){
            return false;
        }
     }
     return true;
    }
};