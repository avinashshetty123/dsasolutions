class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if((long long)num*9<sum||sum<1)return "";
        string res="";
        long long curr=sum;
        for(int i=0;i<num;i++){
            int remain=num-1-i;
            int low=max(0LL,curr-9LL*remain);
            int high=min(9LL,curr);
            int chosen=high;
            res+=to_string(chosen);
            curr-=chosen;
        }
        return res;
        
    }
};