class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 2; // Any subarray of length 2 always satisfies a*b = gcd(a,b)*lcm(a,b)

        for (int i = 0; i < n; i++) {
            long long currProd = 1;
            long long currGcd = 0;
            long long currLcm = 1;

            for (int j = i; j < n; j++) {
                currProd *= nums[j];
                currGcd = (j == i) ? nums[j] : gcd(currGcd, nums[j]);
                currLcm = lcm(currLcm, nums[j]);

                if (currProd == currGcd * currLcm) {
                    maxLen = max(maxLen, j - i + 1);
                }

                // Prevent overflow: max possible (gcd * lcm) for elements <= 10 is 25200
                if (currProd > 25200) break;
            }
        }
        return maxLen;
    }
};