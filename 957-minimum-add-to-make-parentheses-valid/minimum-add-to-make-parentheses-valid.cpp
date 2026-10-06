class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int mini=0;
        for(char c:s){
            if(c=='('){
                ans++;
            }
            else{
                ans>0?ans--:mini++;
            }
        }
        return mini+ans;
    }
};