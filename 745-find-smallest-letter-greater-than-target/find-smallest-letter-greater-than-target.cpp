class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int numb=target-'a';
        int mini=INT_MAX;
        int idx=-1;
        for(int i=0;i<letters.size();i++){
            int num2=letters[i]-'a';
            int val=num2-numb;
            if(val>0&&mini>val){
                mini=min(mini,val);
                idx=i;
            }
          
        }
        return idx==-1?letters[0]:letters[idx];
    }
};