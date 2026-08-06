class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        while(i>=n){
            int s=i;
            int multi=1;
            while(s>0){
                multi*=(s%10);
                s/=10;  
            }
            if(multi%t==0)return i;
            i++;
        }
        return -1;
    }
};