class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(char i:s){
            if(isalnum(i))
            ans+=tolower(i);

        }
       int i=0;
       int j=ans.size()-1;
       while(i<j){
        if(ans[i]!=ans[j])return false;
        i++;
        j--;
       }
       return true;
    }
};