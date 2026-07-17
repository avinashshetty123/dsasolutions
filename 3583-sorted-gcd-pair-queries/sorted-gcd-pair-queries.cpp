class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
     int maxi=*max_element(nums.begin(),nums.end());
     vector<long long>count(maxi+1,0);
     for(int x:nums){
        count[x]++;

     }
     vector<long long>gcd_c(maxi+1,0);
     for(int g=maxi;g>=1;g--){
        long long multi=0;
        for(int m=g;m<=maxi;m+=g){
            multi+=count[m];
        }
        long long total=(multi*(multi-1))/2;
        for(int m=2*g;m<=maxi;m+=g){
            total-=gcd_c[m];
        }
        gcd_c[g]=total;
     }
     vector<long long>prefix_s(maxi+1,0);
     for(int i=1;i<=maxi;i++){
        prefix_s[i]=prefix_s[i-1]+gcd_c[i];
     }
     vector<int>ans;
     for(long long q:queries){
        auto it=upper_bound(prefix_s.begin(),prefix_s.end(),q);
        ans.push_back(distance(prefix_s.begin(),it));
     }
     return ans;
    }
};