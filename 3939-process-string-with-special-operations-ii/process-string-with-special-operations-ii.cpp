class Solution {
public:
    char processStr(string s, long long k) {
     int n=s.size();
     vector<long long>lengths(n);
     long long curr=0;
     for(int i=0;i<n;i++){
        if(s[i]=='*'){
            if(curr>0)curr--;
        }else if(s[i]=='%'){

        }else if(s[i]=='#'){
            curr*=2;
        }else{
            curr++;
        }
        lengths[i]=curr;
     }
     if(k<0||k>=curr){
        return '.';
     }
     for(int i=n-1;i>=0;i--){
        long long len=lengths[i];
        if(s[i]=='#'){
            long long prev=len/2;
            if(prev>0){
                k%=prev;
            }
        }
        else if(s[i]=='%'){
            if(len>0){
                k=(len-1)-k;
            }
        }else if(s[i]=='*'){

        }else{
            if(k==len-1){
                return s[i];
            }
        }
     }
     return '.';
    }
};