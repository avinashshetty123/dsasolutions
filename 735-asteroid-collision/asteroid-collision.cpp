class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
  stack<int>st;
 for(int i:asteroids){
    int curr=i;
    while(!st.empty()&&curr<0&&st.top()>0){
        int top=st.top();
        if(abs(curr)>abs(top)){
            st.pop();
        }else if(abs(curr)==abs(top)){
            st.pop();
            curr=0;
            break;
        }else{
            curr=0;
            break;
        }
    }
    if(curr!=0){
        st.push(curr);
    }
 }
 vector<int>ans;
 while(!st.empty()){

ans.push_back(st.top());
st.pop();

 }
 reverse(ans.begin(),ans.end());
 return ans;    }
};