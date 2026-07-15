class Solution {
public:
int gcd(int a,int b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(b,a%b);
}
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        int sumEven=0;
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                sumEven+=i;
            }
            else{
                sumOdd+=i;
            }

        }
        return gcd(sumEven,sumOdd);
    }
};