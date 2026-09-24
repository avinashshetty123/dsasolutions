class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
    
                int s=nums[i];
                int digi=0;
                while(s>0){
                    digi+=s%10;
                    s/=10;
                }
                if(digi==i){
                    return i;
                }
            
        }
        return -1;
    }
};