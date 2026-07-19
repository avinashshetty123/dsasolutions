class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>last(26,0);
        vector<bool>seen(26,false);
        string res="";
        for(int i=0;i<s.length();i++){
            last[s[i]-'a']=i;
        }
        for(int i=0;i<s.length();i++){
            char curr=s[i];
            if(seen[curr-'a']){
                continue;
            }
            while(!res.empty()&&res.back()>curr&&last[res.back()-'a']>i){
                seen[res.back()-'a']=false;
                res.pop_back();
            }
            res.push_back(curr);
            seen[curr-'a']=true;

        }
        return res;
    }
};