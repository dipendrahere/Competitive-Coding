#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,n;
	cin>>a>>b>>c>>n;
	if(a >= n || b>=n || c>=n){
		cout<<"-1\n";
		return 0;
	}
	int d = n-a-b+c;
	if(c>a||c>b){
		cout<<"-1\n";
		return 0;
	}
	if(a+b-c>=n){
		cout<<"-1\n";
		return 0;
	}
	
	if(d >= 1){
		cout<<d<<endl;
	}
	else{
		cout<<"-1\n";
	}
}
