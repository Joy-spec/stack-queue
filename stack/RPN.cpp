//leetcode 150 Evaluate Reverse Polish Notation
//You should pay attention to the order of the two operands
//the first poped element is the second operand
class Solution {
public:
    bool isDigit(string &s){
        return !(s=="+"||s=="-"||s=="*"||s=="/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int val2,val1;
        for(auto &s:tokens){
            if(isDigit(s)) st.push(stoi(s));
            else{
                val2=st.top();
                st.pop();
                val1=st.top();
                st.pop();
                if(s=="+"){
                    val1+=val2;
                    st.push(val1);
            }
                if(s=="-"){
                    val1-=val2;
                    st.push(val1);
            }
                if(s=="*"){
                    val1*=val2;
                    st.push(val1);
            }
                if(s=="/"){
                    val1/=val2;
                    st.push(val1);
            }
        }
    }
    return st.top();
    }
};
