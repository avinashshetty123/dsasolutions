class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=nums[0];
        int n=nums.size();
        vector<int>prefixGcd(nums.size());
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefixGcd[i]=__gcd(nums[i],maxi);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        for(int i:prefixGcd){
            cout<<i<<"\t";
        }
        long long ans=0;
        int left=0;
        int right=prefixGcd.size()-1;
        cout<<endl;
        while(left<right){
            ans+=__gcd(prefixGcd[left],prefixGcd[right]);
       
            left++;
            right--;
        }
        return ans;
    }
};