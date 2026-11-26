class Solution {
public:
    bool canAliceWin(int n) {
        int dice=10;
        bool isalice=true;

        while(n>=dice){
            n-=dice;
            dice--;
    

            isalice=!isalice;
        }
        return !isalice;
        
    }
};