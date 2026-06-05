class Solution {
public:
struct Node{
    long long cnt;
    long long wav;
    Node(long long c=0,long long w=0):cnt(c),wav(w){}
};
string s;
Node dp[20][11][11][2][2];
bool vis[20][11][11][2][2];
Node dfs(int pos,int prev1,int prev2,bool started,bool tight){
    if(pos==s.size()){
        return Node(1,0);
    }
    if(!tight&&vis[pos][prev1][prev2][started][0]){
        return dp[pos][prev1][prev2][started][0];
    }
    int limit=tight?s[pos]-'0':9;
    Node ans;
    for(int d=0;d<=limit;d++){
        bool ntight=tight&&(d==limit);
        if(!started&&d==0){
            Node child=dfs(pos+1,10,10,false,ntight);
            ans.cnt+=child.cnt;
            ans.wav+=child.wav;
        }
        else if(!started){
            Node child=dfs(pos+1,d,10,true,ntight);
            ans.cnt+=child.cnt;
            ans.wav+=child.wav;
        }else{
            Node child=dfs(pos+1,d,prev1,true,ntight);
            long long extra=0;
            if(prev2!=10){
                if((prev1>prev2&&prev1>d)||(prev1<prev2&&prev1<d)){
                    extra=child.cnt;
                }
            }
            ans.cnt+=child.cnt;
            ans.wav+=child.wav+extra;
        }
    }
    if(!tight){
        vis[pos][prev1][prev2][started][0]=true;
        dp[pos][prev1][prev2][started][0]=ans;
    }
    return ans;
}
long long solve(long long x){
    if(x<0)return 0;
    s=to_string(x);
    memset(vis,0,sizeof(vis));
    return dfs(0,10,10,false,true).wav;
}
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2)-solve(num1-1);
    }
};