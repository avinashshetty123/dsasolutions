class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
     int m=grid.size();
     int n=grid[0].size();
     int layers=min(m,n)/2;
     for(int l=0;l<layers;l++){
        vector<int>nums;
        int top=l;
        int left=l;
        int bot=m-l-1;
        int right=n-l-1;
        for(int j=left;j<=right;j++){
            nums.push_back(grid[top][j]);
        }
        for(int i=top+1;i<=bot;i++)
        nums.push_back(grid[i][right]);
        for(int j=right-1;j>=left;j--)
        nums.push_back(grid[bot][j]);
        for(int i=bot-1;i>top;i--)
        nums.push_back(grid[i][left]);
        int len=nums.size();
        int rot=k%len;
        vector<int>rotated(len);
        for(int i=0;i<len;i++)
        rotated[i]=nums[(i+rot)%len];
        int idx=0;
        for(int j=left;j<=right;j++)
        grid[top][j]=rotated[idx++];
        for(int i=top+1;i<=bot;i++)
        grid[i][right]=rotated[idx++];
        for(int j=right-1;j>=left;j--){
            grid[bot][j]=rotated[idx++];
        }
        for(int i=bot-1;i>top;i--)
        grid[i][left]=rotated[idx++];


     }
     return grid;
    }
};