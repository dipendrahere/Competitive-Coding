#include<bits/stdc++.h>
using namespace std;
int main(){
	int p;
	int a;
	int b;
	cin>>p>>a>>b;
	if(a == 1){
		cout<<"YES\n"<<p<<" "<<0<<endl;
	}
	else if(b== 1){
		cout<<"YES\n"<<0<<" "<<p<<endl;
	}
	else if(p%a == 0){
		cout<<"YES\n"<<p/a<<" "<<0<<endl;
	}
	else if(p%b==0){
		cout<<"YES\n"<<0<<" "<<p/b<<endl;
	}
	else{
		for(int i = 1;i*a <= p; i++){
			if((p - a*i)%b == 0){
				cout<<"YES\n"<<i<<" "<<(p - a*i)/b<<endl;
				return 0;
			}
		}
		cout<<"NO"<<endl;
	}
}
