class Solution {
public:
const int MOD=1e9+7;
int maxi=0;
void dfs(int node,int p,int curr,const vector<vector<int>>&adj){
    maxi=max(maxi,curr);
    for(int i:adj[node]){
        if(i!=p){
            dfs(i,node,curr+1,adj);
        }
    }
}
long long power(long long base,long long exp){
    long long res=1;
    base%=MOD;
    while(exp>0){
        if(exp%2==1)res=(res*base)%MOD;
        base=(base*base)%MOD;
        exp/=2;
    }
    return res;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto i:edges){
          adj[i[0]].push_back(i[1]);
          adj[i[1]].push_back(i[0]);
        }
        maxi=0;
        dfs(1,0,0,adj);
        return power(2,maxi-1);
    }
};