class Solution {
public:
    int maxProduct(int n) {
        int ans=0;
        vector<int>res;
        while(n>0){
            res.push_back(n%10);
            n/=10;
        }
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res.size();j++){
                if(i==j)continue;
                ans=max(ans,res[i]*res[j]);
            }
        }
        return ans;
        
    }
};