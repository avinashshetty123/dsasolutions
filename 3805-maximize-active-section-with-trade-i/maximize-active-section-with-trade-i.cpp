class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans = 0;
        int count = 0;
        for (char i : s) {
            if (i == '1')
                count++;
       }
        string t = "1" + s + "1";

        vector<pair<char,int>>blocks;
        int n=t.size();
        int i=0;
        while(i<n){
            char ch=t[i];
            int len=0;
            while(i<n&&t[i]==ch){
                len++;
                i++;
            }
            blocks.push_back({ch,len});

        }
        int maxi=0;
        for(int b=1;b<blocks.size()-1;b++){
            if(blocks[b].first=='1'){
                if(blocks[b-1].first=='0'&&blocks[b+1].first=='0'){
                    int gain=blocks[b-1].second+blocks[b+1].second;
                    maxi=max(maxi,gain);
                }
            }

        }
        return count+maxi;
    }
};