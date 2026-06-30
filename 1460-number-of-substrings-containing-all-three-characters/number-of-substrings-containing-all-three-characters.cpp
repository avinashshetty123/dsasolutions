class Solution {
public:
    int numberOfSubstrings(string s) {
      vector<int>count(3,0);
      int left=0;
      int total=0;
      int n=s.size();
      for(int r=0;r<n;r++){
        count[s[r]-'a']++;

      while(count[0]>0&&count[1]>0&&count[2]>0){
        total+=(n-r);
        count[s[left]-'a']--;
        left++;
      }
      }
     
    return total;
    }
};