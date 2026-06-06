class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>right(n+1),left(n+1);
        left[0]=0;
        right[n-1]=0;
        for(int i=0;i<nums.size();i++){
            left[i+1]=left[i]+nums[i];
        
        }

        for(int i=nums.size()-1;i>0;i--){
            right[i-1]=right[i]+nums[i];
            cout<<right[i]<<"\t";
        }
        cout<<endl;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            cout<<left[i]<<"\t"<<right[i]<<endl;
            ans[i]=abs(left[i]-right[i]);
        }
        return ans;
    }
};