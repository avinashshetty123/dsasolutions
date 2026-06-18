class Solution {
public:
    double angleClock(int hour, int minutes) {
       double hourhand=(hour*30)+(minutes*0.5);
       int minit=minutes*6;
       double maxi=abs(hourhand-minit);
       if(maxi>180){
        return 360-maxi;
       }else{
        return maxi;
       }
       
    }
};