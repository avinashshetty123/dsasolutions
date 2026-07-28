class Solution {
public:
    string smallestPalindrome(string s) {
        if (s.size() < 1)
            return s;
        map<char, int> mp;

        for (char i : s) {
            mp[i]++;
        }
        string left = "";
        string mid = "";
        string right;

        for (auto i : mp) {
            if (i.second % 2 != 0)
                mid = i.first;
        left.append(i.second / 2, i.first);
        }
    
    right = left;
    reverse(right.begin(), right.end());

    return left + mid + right;
}
}
;