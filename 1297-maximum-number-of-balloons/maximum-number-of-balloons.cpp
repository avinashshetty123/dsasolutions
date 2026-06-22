class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char, int> mp;
        for (char i : text) {
            if (i == 'b' || i == 'a' || i == 'l' || i == 'o' || i == 'n') {
                mp[i]++;
            }
        }
        if (mp.size() < 5) {
            return 0;
        }
        int ans = 0;
        for (auto i : mp) {
            cout << i.first << i.second << endl;
        }
        int cnt = mp['a'];
        for (auto i : mp) {
          if(i.first=='o'||i.first=='l'){
            cnt=min(cnt,i.second/2);
          }
          else{
            cnt=min(cnt,i.second);
          }
        }
        return cnt;
    }
};