class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/" ){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                int ans=0;
                if(tokens[i]=="+"){
                    ans=ans+(num1+num2);
                }else if(tokens[i]=="-"){
                    ans=ans+(num2-num1);
                }else if(tokens[i]=="*"){
                    ans=ans+(num1*num2);
                }else{
                    ans=ans+(num2/num1);
                }
                st.push(ans);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
