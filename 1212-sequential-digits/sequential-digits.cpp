class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
       string digit="123456789";
       int low_len=to_string(low).size();
       int high_len=to_string(high).size();
       for(int i=low_len;i<=high_len;i++){
        for(int s=0;s<=9-i;s++){
            string sub=digit.substr(s,i);
            int num=stoi(sub);
            if(num>=low&&num<=high){
                ans.push_back(num);
            }

        }
       }
       return ans;
    }
};