class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int maxi=0;
        for(int row=-(n-1);row<n;++row){
            for(int col=-(n-1);col<n;++col){
                int curr=0;
                for(int r=0;r<n;r++){
                    for(int c=0;c<n;c++){
                        int img2_r=r+row;
                        int img2_c=c+col;
                        if(img2_r>=0&&img2_r<n&&img2_c>=0&&img2_c<n){
                            if(img1[r][c]==1&&img2[img2_r][img2_c]==1){
                                curr++;
                            }
                        }
                }
                }
                maxi=max(maxi,curr);
            }
        }
        return maxi;
    }
};