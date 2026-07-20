class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
      int m=grid.size();
      int n=grid[0].size();
      int totalEle=m*n;
      vector<vector<int>>ans(m,vector<int>(n));
      k=k%totalEle;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int newId=(i*n+j+k)%totalEle;
            int newR=newId/n;
            int newC=newId%n;
            ans[newR][newC]=grid[i][j];
        }
      }
      return ans;
    }
};