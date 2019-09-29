#include<iostream>
#include<stack>
struct node{
	int n;
	char x;
	char y;
	char z;
	node(int pn,char px,char py,char pz):n(pn),x(px),y(py),z(pz){
	}
};
using namespace std;
int solveHanoi(int n,char x,char y,char z){
	int transport=0;
	if(n==1) {
		cout<<x<<"->"<<z<<endl;	
		transport=1;
	}
	else{
		int count1=solveHanoi(n-1,x,z,y);
		cout<<x<<"->"<<z<<endl;
		int  count2=solveHanoi(n-1,y,x,z);
		transport=1+count1+count2;
	}
	return transport;
}
int solveHanoi2(int n,char x,char y,char z){
	stack<node> s;
	s.push(node(n,x,y,z));
	int transport=0;
	while(!s.empty()){
		node tmp=s.top();
		s.pop();
		if(tmp.n==1){
			cout<<tmp.x<<"->"<<tmp.z<<endl;
			transport++;	
		} 
		else{
			//注意这里的压栈顺序是与递归调用的顺序恰好相反的
			//因为栈是后进先出，因此递归时先执行的要后入栈 
			s.push(node(tmp.n-1,tmp.y,tmp.x,tmp.z));
			//注意这里，不像递归调用中直接输出了x->z
			//这时因为，子问题是在出栈的时候解决的，如果这里直接写成x->z意味着这个操作先于两个子问题的解决发生
			//而事实上这个操作应该夹在两个子问题之间解决 
			s.push(node(1,tmp.x,tmp.y,tmp.z));
			s.push(node(tmp.n-1,tmp.x,tmp.z,tmp.y));
		}
	}
	return transport;
}
int main(){
	int n;
	cin>>n;
	int times=0;
	times=solveHanoi(n,'x','y','z');
	cout<<"total transport times: "<<times<<endl;
	times=solveHanoi2(n,'x','y','z');
	cout<<"total transport times: "<<times<<endl;
}
