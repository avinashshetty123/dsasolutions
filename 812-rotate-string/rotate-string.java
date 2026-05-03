class Solution {
    public boolean rotateString(String s, String goal) {
        if(s.length()!=goal.length())return false;
       String doubled=s+s;
       int n=s.length();
       for(int i=0;i<n;i++){
        boolean check=true;
        for(int j=0;j<n;j++){
            if(doubled.charAt(i+j)!=goal.charAt(j)){
                check=false;
                break;
            }
        }
        if(check)return true;
       }
       return false;
    }
}