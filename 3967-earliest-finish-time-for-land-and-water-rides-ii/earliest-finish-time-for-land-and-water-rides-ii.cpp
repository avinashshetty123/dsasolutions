class Solution {
public:
long long solve(vector<int>&Ast,vector<int>&Adur,vector<int>&Bst,vector<int>&Bdur){
    int n=Ast.size();
    int m=Bst.size();
    vector<pair<int,int>>ridesB;
    for(int i=0;i<m;i++)ridesB.push_back({Bst[i],Bdur[i]});
    sort(ridesB.begin(),ridesB.end());
    vector<int>starts(m);
    vector<long long>prefDur(m);
    vector<long long>suffStartDur(m);
    for(int i=0;i<m;i++){
        starts[i]=ridesB[i].first;
    }
    prefDur[0]=ridesB[0].second;
    for(int i=1;i<m;i++){
        prefDur[i]=min(prefDur[i-1],(long long)ridesB[i].second);

    }
    suffStartDur[m-1]=(long long)ridesB[m-1].first+ridesB[m-1].second;
    for(int i=m-2;i>=0;i--){
        suffStartDur[i]=min(suffStartDur[i+1],(long long)ridesB[i].first+ridesB[i].second);

    }
    long long ans=LLONG_MAX;
    for(int i=0;i<n;i++){
        long long finishA=(long long)Ast[i]+Adur[i];
        int idx=upper_bound(starts.begin(),starts.end(),finishA)-starts.begin();
        if(idx>0){
            ans=min(ans,finishA+prefDur[idx-1]);
            
        }
        if(idx<m){
            ans=min(ans,suffStartDur[idx]);
        }
    }
    return ans;
}
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
       long long ans=LLONG_MAX;
       ans=min(ans,solve(landStartTime,landDuration,waterStartTime,waterDuration));
       ans=min(ans,solve(waterStartTime,waterDuration,landStartTime,landDuration));
       return (int)ans;
    }
};