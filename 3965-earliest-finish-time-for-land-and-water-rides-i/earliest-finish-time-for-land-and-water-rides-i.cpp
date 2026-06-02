class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
                            int ans=1e9;
      for(int i=0;i<landStartTime.size();i++){
        for(int j=0;j<waterStartTime.size();j++){
            int landFinish=landStartTime[i]+landDuration[i];
            ans=min(ans,max(landFinish,waterStartTime[j])+waterDuration[j]);
            int waterFinish=waterStartTime[j]+waterDuration[j];
            ans=min(ans,max(waterFinish,landStartTime[i])+landDuration[i]);
            
        }
      }
      return ans;
    }
};