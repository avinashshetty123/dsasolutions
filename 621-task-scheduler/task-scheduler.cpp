class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>count;
        int maxi=0;
        for(char i:tasks){
            count[i]++;
            maxi=max(maxi,count[i]);
        }
        int max_f=0;
        for(auto const&[t,f]:count){
            if(f==maxi){
                max_f++;
            }
        }
        int ans=(maxi-1)*(n+1)+max_f;
        return max((int)tasks.size(),ans);
    }
};