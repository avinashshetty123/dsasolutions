class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int>count;
        for(int i:nums){
            count[i]++;
        }
        int maxi=1;
        if(count.find(1)!=count.end()){
            int ones=count[1];
            if(ones%2==0){
                maxi=max(maxi,ones-1);
            }else{
                maxi=max(maxi,ones);
            }
        }
        for(auto&[num,freq]:count){
            if(num==1)continue;
            long long curr=num;
            int curr_len=0;
            while(count.find(curr)!=count.end()&&count[curr]>=2){
                curr_len+=2;
                curr=curr*curr;
                if(curr>1e9)break;
            }
            if(count.find(curr)!=count.end()&&count[curr]>=1){
                curr_len+=1;
            }else{
                curr_len-=1;
            }
            maxi=max(maxi,curr_len);
        }
        return maxi;
    }
};