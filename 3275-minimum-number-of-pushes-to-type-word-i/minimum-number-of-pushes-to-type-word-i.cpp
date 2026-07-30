class Solution {
public:
    int minimumPushes(string word) {
        int ones = 8;
        int twos = 8;
        int threes = 8;
        int sum = 0;
        for (char i : word) {
            if (ones > 0) {
                ones--;
                sum += 1;
            } else if (twos > 0) {
                twos--;
                sum += 2;
            } else if (threes > 0) {
                threes--;
                sum += 3;
            } else {
                sum += 4;
            }
        }
        return sum;
    }
};