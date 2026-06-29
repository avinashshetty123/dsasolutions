class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string>st;
        for(int i=0;i<word.size();i++){
            for(int j=i;j<word.size();j++){
                st.insert(word.substr(i,j-i+1));
            }
        }
        int count=0;
        for(string i:patterns){
            if(st.count(i)){
                count++;
            }
        }
        return count;
    }
};