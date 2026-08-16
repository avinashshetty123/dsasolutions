class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
     int cnt0=0,cnt1=0,cnt2=0;
     for(int i:stones){
        int r=i%3;
        if(r==0)cnt0++;
        else if(r==1)cnt1++;
        else cnt2++;
     }
     if(cnt0%2==0){
        return cnt1>0&&cnt2>0;
     }
     return abs(cnt1-cnt2)>2;
    }
};