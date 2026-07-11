class Solution {
public:
    void dfs(int n, vector<vector<int>>& adj, vector<bool>& vis, int& node,int& edge) {
        vis[n] = true;
        node++;
        edge += adj[n].size();
        for (int i : adj[n]) {
            if (!vis[i]) {
                dfs(i, adj, vis, node, edge);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int node = 0;
                int edge = 0;
                dfs(i, adj, vis, node, edge);
                if (edge == node * (node - 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};