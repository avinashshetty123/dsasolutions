class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int>mp;
        
        vector<vector<string>>ans;
        for(string i:strs){
            string proxy=i;
            sort(proxy.begin(),proxy.end());
            if(mp.find(proxy)!=mp.end()){
                
                ans[mp[proxy]].push_back(i);
            }
            else{
                mp[proxy]=ans.size();
                ans.push_back({i});
            }

        }
        return ans;
    }
};