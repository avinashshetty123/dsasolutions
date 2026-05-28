class Solution {
    struct Trie{
        int children[39];
        int bestlen;
        int bestIdx;
        Trie(){
            fill(begin(children),end(children),-1);
            bestlen=1e9;
            bestIdx=1e9;
        }
    };
public:

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
      vector<Trie>t;
      t.emplace_back();
      for(int i=0;i<wordsContainer.size();i++){
        int len=wordsContainer[i].length();
        int curr=0;
        if(len<t[curr].bestlen||(len==t[curr].bestlen&&i<t[curr].bestIdx)){
            t[curr].bestIdx=i;
            t[curr].bestlen=len;
        }
        for(int j=len-1;j>=0;j--){
            int charIdx=wordsContainer[i][j]-'a';
            if(t[curr].children[charIdx]==-1){
                t[curr].children[charIdx]=t.size();
                t.emplace_back();
            }
            curr=t[curr].children[charIdx];
            if(len<t[curr].bestlen||(len==t[curr].bestlen&&i<t[curr].bestIdx)){
                t[curr].bestlen=len;
                t[curr].bestIdx=i;
            }
        }
      }
      vector<int>ans;
      ans.reserve(wordsQuery.size());
      for(const string &q:wordsQuery){
        int curr=0;
        int len=q.length();
        for(int j=len-1;j>=0;j--){
            int charIdx=q[j]-'a';
            if(t[curr].children[charIdx]==-1){
                break;
            }
            curr=t[curr].children[charIdx];

        }
        ans.push_back(t[curr].bestIdx);

      } return ans; 
    }
};