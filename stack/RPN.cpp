#include<iostream>
#include<list>
#include<iterator>
#include<stack> 
#include<vector>
#include<string>
using namespace std;
//leetcode 150 Evaluate Reverse Polish Notation
//You should pay attention to the order of the two operands
//the first poped element is the second operand
class Solution {
public:
    //判断是否为数字
    static bool isDigit(string &s){
        return !(s=="+"||s=="-"||s=="*"||s=="/");
    }
    //根据逆波兰式求值
    static int evalRPN(vector<string>& tokens) {
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
	//判断运算符优先级，a代表表达式中取出的运算符，b代表栈顶运算符
    static bool isPriority(string &a,string &b){
    	if(a=="*"||a=="/"){
    		if(b=="*" || b=="/") return false;
    		else return true;
		}
		if(a=="+" || a=="-") return false; 
	}
	//将中缀表达式转变成逆波兰式
    static vector<string>& make_RPN(const string &s,vector<string> &v){
		int c=0;
		stack<string> s1;
		while(c != s.size()){
			//是运算符
			if(s[c]=='+'||s[c]=='-'||s[c]=='*'||s[c]=='/'){
				string t;
				t.push_back(s[c]);
				if(s1.empty()||isPriority(t,s1.top())){
					s1.push(t);
					cout<<"push into S1: "<<t<<endl;
				}
				else{
					do{
						v.push_back(s1.top());
						cout<<"pop from S1 and then push into v: "<<s1.top()<<endl;
						s1.pop();
					}while(!s1.empty() && !isPriority(t,s1.top()));
					s1.push(t);
					cout<<"push into S1: "<<t<<endl;
				} 
				c++;
			}
			//是数字，则需要取出完整的数字
			else{
				string t;
				while(s[c]>='0'&&s[c]<='9') t.push_back(s[c++]);
				v.push_back(t);
				cout<<"push num into S2: "<<t<<endl;
			}
		}
		while(!s1.empty()){
			v.push_back(s1.top());
			cout<<"pop from S1 and then push into v: "<<s1.top()<<endl;
			s1.pop();
		}
		return v;
	}
};
int main(){
	string s;
	getline(cin,s);
	cout<<"-------------------------------------------"<<endl;
	vector<string> v;
	Solution::make_RPN(s,v);
	cout<<"-------------------------------------------"<<endl;
	cout<<Solution::evalRPN(v);
} 
