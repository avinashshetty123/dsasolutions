class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int height=0;
        int curr=0;
        for(int i:gain){
            height+=i;
            curr=max(curr,height);
        }
        return curr;
    }
};