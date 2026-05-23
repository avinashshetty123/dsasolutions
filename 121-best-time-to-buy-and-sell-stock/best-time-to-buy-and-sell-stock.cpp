class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
      int left=0;
      for(int right=0;right<prices.size();right++){
        maxi=max(maxi,prices[right]-prices[left]);
        while(prices[left]>prices[right]){
            left++;
        }
      }
      return maxi; 
    }
};