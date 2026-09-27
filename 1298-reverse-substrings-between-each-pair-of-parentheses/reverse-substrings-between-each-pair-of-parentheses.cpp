class Solution {
public:
    string reverseParentheses(string s) {
    stack<char>st;
    for(char c:s){
        if(c==')'){
            string temp="";
            while(!st.empty()&&st.top()!='('){
                temp+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
            for(char ch:temp){
                st.push(ch);
            }
        }else{
            st.push(c);
        }
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};