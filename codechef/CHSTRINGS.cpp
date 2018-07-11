#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int st = -1;
		int l = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] >= '0' && s[i] <='9'){
				st = i;
				break;
			}
			else{
				l++;
			}
		}
		int n = 0;
		for(int i = st;i < s.size();i++){
			n = n*10 + s[i]-'0';
		}
		if(n != l){
			cout<<"Shock\n";
		}
		else{
			cout<<"Rock\n";
		}
	}
}
