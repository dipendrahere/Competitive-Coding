#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a < b){
			int temp = b;
			b = a;
			a = temp;
		}
		while(a!=b && a!=0 && b!=0){
			a = a - ceil((a-b+0.0)/(b+0.0))*b;
			if(a < b){
			int temp = b;
			b = a;
			a = temp;
		}
			//cout<<a<<" "<<b<<endl;
		}
		cout<<a+b<<endl;
	}
}
