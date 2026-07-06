class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end(),[](const vector<int>&x,const vector<int>&y){
        if(x[0]==y[0])return x[1]>y[1];
        return x[0]<y[0];
      });
      int ans=0;
      int maxi=0;
      for(const auto&i:intervals){
        int curr=i[1];
        if(curr>maxi){
            ans++;
            maxi=curr;
        }
      }
      return ans;
    }
};