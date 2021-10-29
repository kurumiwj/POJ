#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void clear(stack<string> &s){
	while(!s.empty())
		s.pop();
}

int main(){
	string str,web;
	string b="BACK",f="FORWARD",q="QUIT",v="VISIT";
	stack<string> back,forward;
	back.push("http://www.acm.org/");
	while(true){
		getline(cin,str);
		if(str==q) break;
		else{
			if(str.substr(0,5)==v){
				clear(forward);
				if(web.length()!=0)
					back.push(web);
				web=str.substr(6);
				cout<<web<<endl;
			}else if(str==b){
				if(back.empty())
					cout<<"Ignored"<<endl;
				else{
					forward.push(web);
					web=back.top();
					back.pop();
					cout<<web<<endl;
				}
			}else if(str==f){
				if(forward.empty())
					cout<<"Ignored"<<endl;
				else{
					back.push(web);
					web=forward.top();
					forward.pop();
					cout<<web<<endl;
				}
			}else
				break;
		}
	}
	return 0;
}
